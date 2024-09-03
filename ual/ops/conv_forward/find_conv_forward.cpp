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

#include "ual/ops/conv_forward/find_conv_forward.h"
#include "ual/com/convert.hpp"

using namespace tecoal::ual::common;
using tecoal::ual::args::ConvFwdArgs;

namespace tecoal {
namespace ual {
namespace ops {

#define DB_MAX_USED_SPM_SIZE 225280  // 220K for double buffer
#define FLOAT16_BYTE_SIZE 2
#define MOD32(a) (((size_t)(a)&31) == 0)

size_t findConvForwardWorkspace(const ConvFwdPatchArgs *arg) { return 0; }

int findConvForwardBranch(const ConvFwdPatchArgs *arg) {
    const int N = arg->convf->N;
    const int C = arg->convf->C;
    const int H = arg->convf->H;
    const int W = arg->convf->W;
    const int E = arg->convf->E;
    const int F = arg->convf->F;
    const int M = arg->convf->M;
    const int R = arg->convf->R;
    const int S = arg->convf->S;
    const int PH = arg->convf->pad_h;
    const int PW = arg->convf->pad_w;
    const int SH = arg->convf->stride_h;
    const int SW = arg->convf->stride_w;
    const int DH = arg->convf->dilation_h;
    const int DW = arg->convf->dilation_w;
    const int spe_num = arg->convf->spe_num;

    const int size_y =
        N * E * F * M *
        (arg->y_data_type == UALDataType::UAL_DTYPE_FLOAT ? sizeof(float) : FLOAT16_BYTE_SIZE);

    // Convert the algorithm type to its corresponding index.
    int algo = common::convertAlgoToIndex(arg->algo);

    // Check if the data types for input, weights, and output tensors are all half precision
    // floating points (FP16).
    if (arg->x_data_type == UALDataType::UAL_DTYPE_HALF &&
        arg->w_data_type == UALDataType::UAL_DTYPE_HALF &&
        arg->y_data_type == UALDataType::UAL_DTYPE_HALF) {
        // Check for specific conditions where optimizations can be applied:
        // 1. N, C, and M are all multiples of 32.
        // 2. The kernel size is 1x1 (R=1, S=1).
        // 3. There's no padding (PH=0, PW=0), and the stride is 1x1 (SH=1, SW=1).
        // 4. The dilation is 1x1 (DH=1, DW=1).
        if (MOD32(C) && MOD32(M) && R == 1 && S == 1 && PH == 0 && PW == 0 && SH == 1 && SW == 1 &&
            DH == 1 && DW == 1) {
            // Calculate if the memory required fits within the SPM limits.
            if ((H * W * C + C * R * S * M + E * F * M * 2) * FLOAT16_BYTE_SIZE <
                DB_MAX_USED_SPM_SIZE) {
                // If all conditions are met return the algorithm index for execution.
                return algo;
            }
        }
    }

    return -1;
}

}  // namespace ops
}  // namespace ual
}  // namespace tecoal
