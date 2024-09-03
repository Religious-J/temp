// BSD 3- Clause License Copyright (c) 2024, Tecorigin Co., Ltd. All rights
// reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
// Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
// Neither the name of the copyright holder nor the names of its contributors
// may be used to endorse or promote products derived from this software
// without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY
// WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
// OF SUCH DAMAGE.

#ifndef UAL_OPS_SCATTER_ND_ADD_SCATTER_ND_ADD_HPP_
#define UAL_OPS_SCATTER_ND_ADD_SCATTER_ND_ADD_HPP_

#include "ual/kernel/scatter_nd_add/scatter_nd_add.h"
#include "ual/com/log.h"
#include "ual/args/scatter_nd_add_args.h"
#include "ual/com/def.h"
#include "ual/ops/base_op.hpp"
#include "ual/ops/scatter_nd_add/find_scatter_nd_add.h"

using tecoal::ual::args::ScatterNdAddArgs;
using tecoal::ual::args::ScatterNdAddPatchArgs;
using namespace tecoal::ual::common;
using namespace tecoal::ual::kernel;

namespace tecoal {
namespace ual {
namespace ops {

struct ScatterNdAddType {
    using ArgsType = ScatterNdAddArgs;        // using implement kernel args
    using PatchType = ScatterNdAddPatchArgs;  // using patch args
    using RetType = void;
    using PImplType = void (*)(ArgsType);
};

static ScatterNdAddType::PImplType ScatterNdAddAlgos[] = {
    tecoKernelScatterNdAddIndex32<float>,   tecoKernelScatterNdAddIndex32<half>,
    tecoKernelScatterNdAddIndex32<int>,     tecoKernelScatterNdAddIndex32<double>,
    tecoKernelScatterNdAddIndex32<int64_t>,
    // more branches
};

static const char *ScatterNdAddDiscription[] = {
    "tecoKernelScatterNdAddIndex32<float>",   "tecoKernelScatterNdAddIndex32<half>",
    "tecoKernelScatterNdAddIndex32<int>",     "tecoKernelScatterNdAddIndex32<double>",
    "tecoKernelScatterNdAddIndex32<int64_t>",
    // more branches
};

struct ScatterNdAddOp : public BaseOp<ScatterNdAddOp, ScatterNdAddType> {
 public:
    using ArgsType = typename ScatterNdAddType::ArgsType;    // using implement kernel args
    using PatchType = typename ScatterNdAddType::PatchType;  // using dispatch args
    using RetType = typename ScatterNdAddType::RetType;
    using PImplType = typename ScatterNdAddType::PImplType;

    static const char *name() { return "scatter_nd_add"; }

    Status findImpl(const PatchType *args) {
        ScatterNdAddBranch branch = findScatterNdAddBranch(args);
        if (branch == ScatterNdAddBranch::SCATTER_ND_ADD_END) {
            ERROR("scatter_nd_add branch is not exit!");
            return Status::NOT_IMPLEMENTED;
        }
        int index = static_cast<int>(branch);
        setInstance(ScatterNdAddAlgos[index], ScatterNdAddDiscription[index]);
        return Status::SUCCESS;
    }
};
}  // namespace ops
}  // namespace ual
}  // namespace tecoal

#endif  // UAL_OPS_SCATTER_ND_ADD_SCATTER_ND_ADD_HPP_
