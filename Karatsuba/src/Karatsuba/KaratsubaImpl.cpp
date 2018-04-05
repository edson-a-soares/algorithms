#include "Karatsuba/KaratsubaImpl.h"
#include <stdexcept>
#include <cmath>

namespace Algorithm {
namespace Karatsuba {


    size_t KaratsubaImpl::multiply(std::string multiplicand, std::string multiplier)
    {

        makeDigitsCountEven(multiplicand);
        makeDigitsCountEven(multiplier);

        makeEqualSize(multiplicand, multiplier);

        auto numberSize = multiplicand.size();

        auto multiplicandInteger = std::stoull(multiplicand);
        auto multiplierInteger   = std::stoull(multiplier);

        // It handles the case which operands are single digit numbers.
        if ( multiplicandInteger <= 10 || multiplierInteger <= 10 )
            return multiplicandInteger * multiplierInteger;

        unsigned int halfNumberSize = static_cast<unsigned>(numberSize/2);

        auto multiplicandRight = multiplicand.substr(0, halfNumberSize);
        auto multiplicandLeft  = multiplicand.substr(halfNumberSize, numberSize);

        auto multiplierRight = multiplier.substr(0, halfNumberSize);
        auto multiplierLeft  = multiplier.substr(halfNumberSize, numberSize);

        auto a = multiply(multiplicandRight, multiplierRight);
        auto d = multiply(multiplicandLeft,  multiplierLeft);

        auto e = multiply(
                std::to_string(std::stoull(multiplicandRight) + std::stoull(multiplicandLeft)),
                std::to_string(std::stoull(multiplierRight)   + std::stoull(multiplierLeft))
            ) - a - d;

        return static_cast<size_t>(a * std::pow(NUMBER_BASE, numberSize) + (e * std::pow(NUMBER_BASE, halfNumberSize)) + d);

    }

    void makeDigitsCountEven(std::string &number)
    {
        if ( number.size() % 2 != 0 )
            number = "0" + number;
    }

    void makeEqualSize(std::string &numberOne, std::string &numberTwo)
    {
        unsigned long int firstNumberSize  = numberOne.size();
        unsigned long int secondNumberSize = numberTwo.size();

        if ( firstNumberSize == secondNumberSize )
            return;

        if ( firstNumberSize < secondNumberSize )
            numberOne = fillWithZeros(numberOne, secondNumberSize);

        if ( secondNumberSize < firstNumberSize )
            numberTwo = fillWithZeros(numberTwo, firstNumberSize);
    }

    std::string fillWithZeros(const std::string &number, long int finalSize)
    {
        if ( finalSize < 0 || static_cast<unsigned>(finalSize) <= number.size() )
            throw std::invalid_argument("Invalid Number Final Size");

        std::string result = "";
        for ( long int counter = number.size(); counter < finalSize; counter++ )
            result += "0";

        return result + number;
    }


} }