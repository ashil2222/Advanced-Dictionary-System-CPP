/*
 * SimmilarityMeasure Class - Assignment 2
 *
 * Purpose:
 * This file will define the base class to the similarity measures used 
 * in smart search function.
 *
 * Author: Adhil Ahamed (10739721)
 * Date: 23.10.2026
 */

#ifndef SIMMILARITYMEASURE_H
#define SIMMILARITYMEASURE_H

#include <string>
using namespace std;

/*
 * Class: SimmilarityMeasure
 * Functionality: This is the Base class for calculating the distance
 * between two words using different algorithms.
 * Author: Adhil Ahamed (10739721)
 * Date: 23.10.2026
 */
class SimmilarityMeasure {
public:
    /*
     * Module: calculateDistance()
     * Functionality: This will define a common function to calculate the
     * word similarity distance.
     * 
     * Input: Two strings
     * Output: Integer distance
     * 
     * Author: Adhil Ahamed (10739721)
     * Date: 23.10.2026
     */
    virtual int calculateDistance(const string& word1, const string& word2) const = 0;

    /*
     * Module: getName()
     * Functionality: This will return the algorithm name.
     * 
     * Input: None
     * Output: String containing the algorithm name
     *
     * Author: Adhil Ahamed (10739721)
     * Date: 23.10.2026
     */
    virtual string getName() const = 0;
    virtual ~SimmilarityMeasure() {}
};

/*
 * Class: HammingDistance
 * Functionality: This will count different character positions between
 * two words of equal length.
 * 
 * Created by: Adhil Ahamed (10739721)
 * Date: 23.10.2026
 */
class HammingDistance : public SimmilarityMeasure {
public:
    int calculateDistance(const string& word1, const string& word2) const override;
    string getName() const override;
};

/*
 * Class: LevenshteinDistance
 * Functionality: This will calculate the minimum number of nsertions, 
 * deletions substitutions.
 * 
 * Created by: Adhil Ahamed (10739721)
 * Date: 23.10.2026
 */
class LevenshteinDistance : public SimmilarityMeasure {
public:
    int calculateDistance(const string& word1, const string& word2) const override;
    string getName() const override;
};

/*
 * Class: DamerauLevenshteinDistance
 * Functionality: This will calculate edit distance including adjacent
 * character transpositions.
 * 
 * Author: Adhil Ahamed (10739721)
 * Date: 23.10.2026
 */
class DamerauLevenshteinDistance : public SimmilarityMeasure {
public:
    int calculateDistance(const string& word1, const string& word2) const override;
    string getName() const override;
};

#endif
