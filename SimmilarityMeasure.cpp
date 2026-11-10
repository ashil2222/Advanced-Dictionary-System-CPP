/*
 * SimmilarityMeasure Implementation - Assignment 2
 *
 * Purpose:
 * This file will implements the similarity algorithms that is used by
 * the Smart Search function.
 *
 * Author: Adhil Ahamed (10739721)
 * Date: 23.10.2026
 */

#include "SimmilarityMeasure.h"

#include <vector>
#include <map>
#include <algorithm>

 /*
  * Module: HammingDistance::calculateDistance()
  * Functionality: This will count the number of character positions
  * that will be different between two words of equal length.
  *
  * Input: Two strings
  * Output: The integer will representing the Hamming distance.
  *         Returns -1 if the word lengths are different.
  *
  * Created by: Adhil Ahamed (10739721)
  * Date: 23.10.2026
  */
int HammingDistance::calculateDistance(const string& word1, const string& word2) const {
    if (word1.length() != word2.length()) {
        return -1;
    }
    int distance = 0;
    for (int i = 0; i < static_cast<int>(word1.length()); i++) {
        if (word1[i] != word2[i]) {
            distance++;
        }
    }
    return distance;
}
/*
 * Module: HammingDistance::getName()
 * Functionality: This will returns the name of the similarity algorithm.
 * Input: None
 * Output: String containing the algorithm name.
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 23.10.2026
 */
string HammingDistance::getName() const {
    return "Hamming Distance";
}

/*
 * Module: LevenshteinDistance::getName()
 * Functionality: This will return the name of the
 * similarity algorithm.
 *
 * Input: None
 * Output: String containing the algorithm name.
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 23.10.2026
 */
string LevenshteinDistance::getName() const {
    return "Levenshtein Distance";
}

/*
 * Module: LevenshteinDistance::calculateDistance()
 * Functionality: This will claclulate the minimum number of insertion,
 * deletions and substitutions that is needed to change one word to
 * another
 *
 * Input: Two strings
 * Output: Integer representing the Levenshtein distance.
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 23.10.2026
 */
int LevenshteinDistance::calculateDistance(const string& word1, const string& word2) const {
    int length1 = static_cast<int>(word1.length());
    int length2 = static_cast<int>(word2.length());

    vector<int> previous(length2 + 1);
    vector<int> current(length2 + 1);

    for (int j = 0; j <= length2; j++) {
        previous[j] = j;
    }
    for (int i = 1; i <= length1; i++) {
        current[0] = i;
        for (int j = 1; j <= length2; j++) {
            int cost = 0;
            if (word1[i - 1] != word2[j - 1]) {
                cost = 1;
            }
            int deletion = previous[j] + 1;
            int insertion = current[j - 1] + 1;
            int substitution = previous[j - 1] + cost;
            current[j] = min({ deletion, insertion, substitution });
        }
        previous = current;
    }
    return previous[length2];
}

/*
 * Module: DamerauLevenshteinDistance::calculateDistance()
 * Functionality: This will claculate the minimum number of insertion,
 * deletions, substitutions and character transpositions needed to 
 * change one word to another
 * This algorithm is selected because this can find common spelling
 * mistakes like swapping two letters.
 *
 * This will calculates the distance using insertion, deletion, substitution
 * substitution and transposition of characters.
 *
 * For example, "appel" and "apple" have a distance of 1 using Damerau 
 * Levenshtein Distance.
 *
 * This will make it useful for suggesting dictionary words when the user
 * enter a word with spelling mistake.
 *
 * Input: Two strings
 * Output: Integer representing the Damerau-Levenshtein distance.
 * 
 * Reference:
 * [Wikipedia contributors. (n.d.). Damerau–Levenshtein distance. Wikipedia.
 * https://en.wikipedia.org/wiki/Damerau%E2%80%93Levenshtein_distance]
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 23.10.2026
 */
int DamerauLevenshteinDistance::calculateDistance(const string& word1, const string& word2) const {
    int length1 = static_cast<int>(word1.length());
    int length2 = static_cast<int>(word2.length());
    int maximumDistance = length1 + length2;

    vector<vector<int>> distance(
        length1 + 2, vector<int>(length2 + 2, 0));
    distance[0][0] = maximumDistance;

    for (int i = 0; i <= length1; i++) {
        distance[i + 1][0] = maximumDistance;
        distance[i + 1][1] = i;
    }
    for (int j = 0; j <= length2; j++) {
        distance[0][j + 1] = maximumDistance;
        distance[1][j + 1] = j;
    }
    map<char, int> lastPosition;
    for (int i = 1; i <= length1; i++) {
        int lastMatch = 0;
        for (int j = 1; j <= length2; j++) {
            int previousRow = lastPosition[word2[j - 1]];
            int previousColumn = lastMatch;
            int cost = 1;

            if (word1[i - 1] == word2[j - 1]) {
                cost = 0;
                lastMatch = j;
            }
            int substitution = distance[i][j] + cost;
            int insertion = distance[i + 1][j] + 1;
            int deletion = distance[i][j + 1] + 1;

            int transposition =
                distance[previousRow][previousColumn]
                + (i - previousRow - 1)
                + 1
                + (j - previousColumn - 1);

            distance[i + 1][j + 1] = min({
                substitution,
                insertion,
                deletion,
                transposition
                });
        }
        lastPosition[word1[i - 1]] = i;
    }
    return distance[length1 + 1][length2 + 1];
}
/*
 * Module: DamerauLevenshteinDistance::getName()
 * Functionality: This will return the name of the similarity algorithm.
 * 
 * Input: None
 * Output: String containing the algorithm name.
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 23.10.2026
 */
string DamerauLevenshteinDistance::getName() const {
    return "Damerau-Levenshtein Distance";
}









