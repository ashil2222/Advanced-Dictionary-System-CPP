
/*
 * AlgorithmHelper Class - Assignment 2
 *
 * Purpose:
 * This class will give a helper function to generate random indices for
 * select words from the dictionary.
 *
 * Author: Adhil Ahamed (10739721)
 * Date: 22.10.2026
 */

#ifndef ALGORITHMHELPER_H
#define ALGORITHMHELPER_H

class AlgorithmHelper {

public:
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
    static int getRandomIndex(int max);
};

#endif // ALGORITHMHELPER_H

