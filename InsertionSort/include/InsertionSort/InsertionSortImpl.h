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

#ifndef Algorithm_InsertionSortImpl_INCLUDED
#define Algorithm_InsertionSortImpl_INCLUDED

#include "InsertionSort/InsertionSortInterface.h"

namespace Algorithm {
namespace Sorting {


    class InsertionSortImpl : public Sorting::InsertionSortInterface {
        ///
        /// @implements Algorithm::InsertionSort::InsertionSortInterface
        ///
    public:
        void sort(int [], int length) final;
            /// It sorts an array using Insertion Sort algorithm.
            ///
            /// @param array  The array to be sorted.
            /// @param length The length of the array passed to be sorted.

    };

    void sortValue(int [], int value, int sortedPortionIndex);
        /// It receives an array and it sorts one of its values by sliding it to the left;
        /// the sorted portion of the array.
        ///
        /// @param array              The array where the value must be sorted.
        /// @param value              The value being sorted.
        /// @param sortedPortionIndex The index to the last item in the sorted portion of the array.


} }

#endif
