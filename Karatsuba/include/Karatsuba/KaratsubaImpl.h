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

#ifndef Algorithms_KaratsubaImpl_INCLUDED
#define Algorithms_KaratsubaImpl_INCLUDED

#include "Karatsuba/KaratsubaInterface.h"

namespace Algorithm {
namespace Karatsuba {


    class KaratsubaImpl : public Karatsuba::KaratsubaInterface {
        ///
        /// @implements Algorithm::Karatsuba::KaratsubaInterface
        ///
    public:

        constexpr static int NUMBER_BASE = 10;
            ///
            ///
            ///

        size_t multiply(std::string multiplicand, std::string multiplier) final;
            ///
            /// It performs multiplication of any numbers using the Karatsuba's algorithm.
            ///
            /// @param multiplicand A multiplicand.
            /// @param multiplier   A multiplier.
            /// @see Algorithm::Karatsuba::KaratsubaInterface::multiply(std::string, std::string)
            /// @return The product of the two operands.
            ///

    };


    void makeDigitsCountEven(std::string &number);
        ///
        /// It receives a number with an odd number of digits and make it even.
        ///
        /// @param number A number to be dealt with.
        ///

    void makeEqualSize(std::string &numberOne, std::string &numberTwo);
        ///
        /// It receives two numbers with different amount of digits and it makes them the same size.
        ///
        /// @param numberOne
        /// @param numberTwo
        ///

    std::string fillWithZeros(const std::string &number, long int finalSize);
         ///
         /// It fills a number with zeros until it gets a certain desired size.
         ///
         /// @param number    A number to be processed.
         /// @param finalSize Final desired size to the number.
         /// @return The number with the desired size.
         ///


} }

#endif
