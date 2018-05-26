#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "InsertionSort/InsertionSortInterface.h"
#include "InsertionSort/InsertionSortImpl.h"

using testing::ContainerEq;
using Algorithm::Sorting::InsertionSortImpl;
using Algorithm::Sorting::InsertionSortInterface;

class InsertionSortTest : public ::testing::Test
{
protected:

    void SetUp() override
    {
        insertionSort = new InsertionSortImpl();
    }

    void TearDown() override
    {
        delete insertionSort;
        insertionSort = nullptr;
    }

    InsertionSortInterface * insertionSort = nullptr;

};

TEST_F(InsertionSortTest, SortingValueOnArray) {

    int array [] = { 2, 3, 10, 4, 9, 1 };

    Algorithm::Sorting::sortValue(array, 4, 2);
    int twoBeforeLastSorted [] = { 2, 3, 4, 10, 9, 1 };
    EXPECT_THAT(array, ContainerEq(twoBeforeLastSorted));

    Algorithm::Sorting::sortValue(array, 9, 3);
    int oneBeforeLastSorted [] = { 2, 3, 4, 9, 10, 1 };
    EXPECT_THAT(array, ContainerEq(oneBeforeLastSorted));

    Algorithm::Sorting::sortValue(array, 1, 4);
    int allSorted [] = { 1, 2, 3, 4, 9, 10 };
    EXPECT_THAT(array, ContainerEq(allSorted));

}

TEST_F(InsertionSortTest, SortingEntireArray) {

    int array [] = { 35, 30, 22, 25, 9, 3, 5, 12 };

    insertionSort->sort(array, sizeof(array)/sizeof(int));

    int sorted [] = { 3, 5, 9, 12, 22, 25, 30, 35 };
    EXPECT_THAT(array, ContainerEq(sorted));

}
