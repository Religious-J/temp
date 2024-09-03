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

#ifndef UAL_COM_CONVERT_HPP_
#define UAL_COM_CONVERT_HPP_

#include "ual/com/def.h"

namespace tecoal {
namespace ual {
namespace common {

static int inline convertAlgoToIndex(UALAlgoType type) {
    switch (type) {
        case UALAlgoType::UAL_ALGO_0: return 0;
        case UALAlgoType::UAL_ALGO_1: return 1;
        case UALAlgoType::UAL_ALGO_2: return 2;
        case UALAlgoType::UAL_ALGO_3: return 3;
        case UALAlgoType::UAL_ALGO_4: return 4;
        case UALAlgoType::UAL_ALGO_5: return 5;
        case UALAlgoType::UAL_ALGO_6: return 6;
        case UALAlgoType::UAL_ALGO_7: return 7;
        case UALAlgoType::UAL_ALGO_8: return 8;
        case UALAlgoType::UAL_ALGO_9: return 9;
        case UALAlgoType::UAL_ALGO_10: return 10;
        case UALAlgoType::UAL_ALGO_11: return 11;
        case UALAlgoType::UAL_ALGO_12: return 12;
        case UALAlgoType::UAL_ALGO_13: return 13;
        case UALAlgoType::UAL_ALGO_14: return 14;
        case UALAlgoType::UAL_ALGO_15: return 15;
        case UALAlgoType::UAL_ALGO_16: return 16;
        case UALAlgoType::UAL_ALGO_17: return 17;
        case UALAlgoType::UAL_ALGO_18: return 18;
        case UALAlgoType::UAL_ALGO_19: return 19;
        case UALAlgoType::UAL_ALGO_20: return 20;
        case UALAlgoType::UAL_ALGO_21: return 21;
        case UALAlgoType::UAL_ALGO_22: return 22;
        case UALAlgoType::UAL_ALGO_23: return 23;
        case UALAlgoType::UAL_ALGO_24: return 24;
        case UALAlgoType::UAL_ALGO_25: return 25;
        case UALAlgoType::UAL_ALGO_26: return 26;
        case UALAlgoType::UAL_ALGO_27: return 27;
        case UALAlgoType::UAL_ALGO_28: return 28;
        case UALAlgoType::UAL_ALGO_29: return 29;
        case UALAlgoType::UAL_ALGO_30: return 30;
        case UALAlgoType::UAL_ALGO_31: return 31;
        case UALAlgoType::UAL_ALGO_32: return 32;
        case UALAlgoType::UAL_ALGO_33: return 33;
        case UALAlgoType::UAL_ALGO_34: return 34;
        case UALAlgoType::UAL_ALGO_35: return 35;
        case UALAlgoType::UAL_ALGO_36: return 36;
        case UALAlgoType::UAL_ALGO_37: return 37;
        case UALAlgoType::UAL_ALGO_38: return 38;
        case UALAlgoType::UAL_ALGO_39: return 39;
        case UALAlgoType::UAL_ALGO_40: return 40;
        case UALAlgoType::UAL_ALGO_41: return 41;
        case UALAlgoType::UAL_ALGO_42: return 42;
        case UALAlgoType::UAL_ALGO_43: return 43;
        case UALAlgoType::UAL_ALGO_44: return 44;
        case UALAlgoType::UAL_ALGO_45: return 45;
        case UALAlgoType::UAL_ALGO_46: return 46;
        case UALAlgoType::UAL_ALGO_47: return 47;
        case UALAlgoType::UAL_ALGO_48: return 48;
        case UALAlgoType::UAL_ALGO_49: return 49;
        case UALAlgoType::UAL_ALGO_50: return 50;
        default: {
            throw std::runtime_error("UALAlgoType is not exist!\n");
        }
    }
}

}  // namespace common
}  // namespace ual
}  // namespace tecoal

#endif  // UAL_COM_CONVERT_HPP_
