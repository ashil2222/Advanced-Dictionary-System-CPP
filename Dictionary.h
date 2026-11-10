/*
 * Dictionary Class - Assignment 2
 *
 * Purpose:
 * This call will store the dictionary by using the ector of word object 
 * this gives functions to load the dictirony from the text file then the 
 * search for words and display the dictionary statistics this also will
 * give a menu to the user to select this functions.
 *
 * Author: Adhil Ahamed (10739721)
 * Date: 20.10.2026
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <string>
#include "Word.h"
#include <vector>


using namespace std;

class Dictionary {
protected:
    // This will store every words that are loaded from the dictirony file
    vector<Word> words;

public:
    /*
     * Module: Dictionary()
     * Functionality: Default constructor will create a empty dictionary.
     * Input: None
     * Output: None
     *
     * Created by: Adhil Ahamed (10739721)
     * Date: 20.10.2026
     */
    Dictionary();

    /*
     * Module: void loadDictionary(const string& filename)
     * Functionality: This will read the dictionary file and store the valid 
     * word records like word object in the vector
     * Input: filename - The name or path of the dictionary file
     * Output: This will display the number of successfull loaded records
     * a error message
     *
     * Created by: Adhil Ahamed (10739721)
     * Date: 20.10.2026
     */
    void loadDictionary(const string& filename);

    /*
     * Module: void searchWord()
     * Functionality: This will allow the user search from a word and displays
     * the type of definition if found.
     * 
     * Input: Word entered by the user
     * Output: Displays the search result
     *
     * Created by: Adhil Ahamed (10739721)
     * Date: 20.10.2026
     */
    void searchWord();

    /*
     * Module: void aboutDictionary()
     * Functionality: This will display the satistics about the dictionary,
     * including word types, starting letters and word lengths.
     * Input: None
     * Output: Displays dictionary statistics
     *
     * Created by: Adhil Ahamed (10739721)
     * Date: 20.10.2026
     */
    void aboutDictionary();

    /*
     * Module: virtual void menu()
     * Functionality: This display the dictionary manu and the allow the user
     * to select and run the available task.
     * 
     * Input: Menu selection entered by the user
     * Output: Displays the menu and selected task results
     *
     * Created by: Adhil Ahamed (10739721)
     * Date: 20.10.2026
     */
    virtual void menu();
};

#endif // DICTIONARY_H









 