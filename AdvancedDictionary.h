/*
 * AdvancedDictionary Class - Assignment 2
 *
 * Purpose:
 * This class will extend the dictionary class with a additional function
 * and including the guessimg game and the smart search and it will 
 * overide the menu function to add the new features.
 *
 * Author: Adhil Ahamed (10739721)
 * Date: 22.10.2026
 */

#ifndef ADVANCEDDICTIONARY_H
#define ADVANCEDDICTIONARY_H


#include "Dictionary.h"
#include "SimmilarityMeasure.h"
#include <vector>
#include <memory>

class AdvancedDictionary : public Dictionary {
private:
    vector<unique_ptr<SimmilarityMeasure>> measures;

public:
    /*
     * Module: AdvancedDictionary()
     * Functionality: This is the constructor for the AdvancedDictionary 
     * class.
     * 
     * Input: None
     * Output: None
     *
     * Created by: Adhil Ahamed (10739721)
     * Date: 22.10.2026
     */
    AdvancedDictionary();

    /*
    * Module: void menu() override
    * Functionality: This will overrides the dictionary menu function to
    * put the Guessing Game and Smart Search options.
    * Input: Menu choice entered by the user
    * Output: Displays the advanced dictionary menu
    *
    * Created by: Adhil Ahamed (10739721)
    * Date: 22.10.2026
    */
    void menu() override;

    /*
     * Module: void guessingGame()
     * Functionality: This will run a word guessing game by using reandom
     * words from the loaded dictionary The user can guess words using
     * the showed hints and then earn points for correct mark
     * 
     * Input: Word guesses entered by the user
     * Output: Displays hints, score, lives and game results
     *
     * Created by: Adhil Ahamed (10739721)
     * Date: 22.10.2026
     */
    void guessingGame();

    /*
     * Module: void smartSearch()
     * Functionality: This will find the nearest matching dictionary words
     * by using three different similarity measures.
     * 
     * Input: Word entered by the user
     * Output: Displays the five closest words for each measure
     *
     * Created by: Adhil Ahamed (10739721)
     * Date: 22.10.2026
     */
    void smartSearch();
};

#endif // ADVANCEDDICTIONARY_H 