#include "InsertionSort/InsertionSortImpl.h"

namespace Algorithm {
namespace Sorting {


    void InsertionSortImpl::sort(int array [], int length)
    {

        for ( int i = 1; i < length; i++ )
            sortValue(array, array[i], i - 1);

    }

    void sortValue(int array [], int value, int sortedPortionIndex)
    {

        auto index = sortedPortionIndex;
        for ( ; index >= 0 && array[index] > value; index-- )
            array[index + 1] = array[index];

        array[index + 1] = value;

    }


} }