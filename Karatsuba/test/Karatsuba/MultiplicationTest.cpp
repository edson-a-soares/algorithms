#include "gtest/gtest.h"
#include "Karatsuba/KaratsubaInterface.h"
#include "Karatsuba/KaratsubaImpl.h"

using Algorithm::Karatsuba::KaratsubaImpl;
using Algorithm::Karatsuba::KaratsubaInterface;

class MultiplicationTest : public ::testing::Test
{
protected:

    void SetUp() override
    {
        karatsubaMultiplication = new KaratsubaImpl();
    }

    void TearDown() override
    {
        delete karatsubaMultiplication;
        karatsubaMultiplication = nullptr;
    }

    KaratsubaInterface * karatsubaMultiplication = nullptr;

};

TEST_F(MultiplicationTest, makeNumbersEqualSize) {

    std::string numberOne;
    std::string numberTwo;

    numberOne = "2523";
    numberTwo = "34";
    Algorithm::Karatsuba::makeEqualSize(numberOne, numberTwo);
    ASSERT_EQ(numberOne.size(), numberTwo.size());

    numberOne = "23";
    numberTwo = "3425";
    Algorithm::Karatsuba::makeEqualSize(numberOne, numberTwo);
    ASSERT_EQ(numberOne.size(), numberTwo.size());

}

TEST_F(MultiplicationTest, fillNumberWithZero) {

    ASSERT_EQ("00005",      Algorithm::Karatsuba::fillWithZeros("5",     5));
    ASSERT_EQ("00099",      Algorithm::Karatsuba::fillWithZeros("99",    5));
    ASSERT_EQ("00500",      Algorithm::Karatsuba::fillWithZeros("500",   5));
    ASSERT_EQ("0000025000", Algorithm::Karatsuba::fillWithZeros("25000", 10));

}

TEST_F(MultiplicationTest, InvalidFinalSizeForFillNumberExcetion) {

    EXPECT_THROW(
        Algorithm::Karatsuba::fillWithZeros("5", -5),
        std::invalid_argument
    );

    EXPECT_THROW(
        Algorithm::Karatsuba::fillWithZeros("5000", 4),
        std::invalid_argument
    );

    EXPECT_THROW(
        Algorithm::Karatsuba::fillWithZeros("2500", 2),
        std::invalid_argument
    );

}

TEST_F(MultiplicationTest, KaratsubaForFastMultiplication) {

    ASSERT_EQ(0,                  karatsubaMultiplication->multiply("0",         "0"));
    ASSERT_EQ(1,                  karatsubaMultiplication->multiply("1",         "1"));
    ASSERT_EQ(25,                 karatsubaMultiplication->multiply("5",         "5"));
    ASSERT_EQ(2944,               karatsubaMultiplication->multiply("46",        "64"));
    ASSERT_EQ(53136,              karatsubaMultiplication->multiply("123",       "432"));
    ASSERT_EQ(5332114,            karatsubaMultiplication->multiply("1234",      "4321"));
    ASSERT_EQ(670592745,          karatsubaMultiplication->multiply("12345",     "54321"));
    ASSERT_EQ(80779853376,        karatsubaMultiplication->multiply("123456",    "654321"));
    ASSERT_EQ(9449772114007,      karatsubaMultiplication->multiply("1234567",   "7654321"));
    ASSERT_EQ(9449772114007,      karatsubaMultiplication->multiply("1234567",   "7654321"));
    ASSERT_EQ(1082152022374638,   karatsubaMultiplication->multiply("12345678",  "87654321"));

}
