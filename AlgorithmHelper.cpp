/*
 * AlgorithmHelper Class Implementation - Assignment 2
 *
 * Purpose:
 * This file will implement the random index generation function that
 * is used to select random words for the guessing game.
 *
 * Author: Adhil Ahamed (10739721)
 * Date: 22.10.2026
 */

#include "AlgorithmHelper.h"
#include <cstdlib>

 /*
  * Module: int AlgorithmHelper::getRandomIndex(int max)
  * Functionality: This will generate a random index from 0 up to max
  * including max this will combine two rand() values so it can support
  * ranges larger than RAND_MAX.
  * 
  * Input: The biggest index that may be returned
  * Output: A random index from 0 to max -1 if max is negative
  *
  * Created by: Adhil Ahamed (10739721)
  * Date: 22.10.2026
  */
int AlgorithmHelper::getRandomIndex(int max) {

    // This will stop invalid ranges.
    if (max < 0)
        return -1;

    // This will connect two random numbers to create a larger random range.
    unsigned long long randomNumber =
        static_cast<unsigned long long>(rand()) *
        (static_cast<unsigned long long>(RAND_MAX) + 1ULL)
        + static_cast<unsigned long long>(rand());


    // This will return a index within the dictionary size.
    return static_cast<int>(randomNumber % (static_cast<unsigned long long>(max) + 1ULL));
}


