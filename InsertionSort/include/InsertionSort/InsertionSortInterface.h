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

#ifndef Algorithm_InsertionSortInterface_INCLUDED
#define Algorithm_InsertionSortInterface_INCLUDED

#include <string>

namespace Algorithm {
namespace Sorting {


    class InsertionSortInterface {
        /// It seeks the to define a contract for Insertion Sort algorithm.
        ///
        /// @see https://en.wikipedia.org/wiki/Insertion_sort
        ///
    public:
        virtual ~InsertionSortInterface() = default;

        virtual void sort(int array[], int length) = 0;
            /// It sorts an array using Insertion Sort algorithm.
            ///
            /// @param array  The array to be sorted.
            /// @param length The length of the array passed to be sorted.

    };


} }

#endif
