/*
 * (C) Copyright 2018 Edson (http://edsonaraujosoares.com) and others.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Contributors:
 *     Edson Araújo Soares
 */

#ifndef Algorithm_KaratsubaInterface_INCLUDED
#define Algorithm_KaratsubaInterface_INCLUDED

#include <string>

namespace Algorithm {
namespace Karatsuba {


    class KaratsubaInterface {
        ///
        /// It allows to perform faster multiplications by utilizing Karatsuba's algorithm.
        ///
        /// @see https://en.wikipedia.org/wiki/Karatsuba_algorithm
        ///
    public:
        virtual ~KaratsubaInterface() = default;

        virtual size_t multiply(std::string multiplicand, std::string multiplier) = 0;
            ///
            /// It performs multiplication of any numbers using the Karatsuba's algorithm.
            ///
            /// @param multiplicand The multiplicand number.
            /// @param multiplier   The multiplier number.
            /// @return The product of the two operands.
            ///

    };


} }

#endif
