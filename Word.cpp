/*
 * Word Class Implementation - Assignment 2
 *
 * Purpose:
 * This file has the implementation of the Word class functions this will 
 * initialize word object and the provide the functions to retrieve and 
 * update the name, type and definition of the word
 *
 * Author: Adhil Ahamed (10739721)
 * Date: 16.10.2026
 */

#include "Word.h"

 /*
  * Module: Word()
  * Functionality: Default constructor that initializes the words properties
  * with empty strings.
  * Input: None
  * Output: None
  *
  * Created by: Adhil Ahamed (10739721)
  * Date: 16.10.2026
  */
Word::Word() {
    name = "";
    type = "";
    definition = "";
}

/*
 * Module: Word(string n, string t, string d)
 * Functionality: Parameterized constructor that is assigned in the provided
 * values to the word's properties.
 * Input:
 *   n - The name of the word
 *   t - The type of the word
 *   d - The definition of the word
 * Output: None
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 16.10.2026
 */
Word::Word(string n, string t, string d) {
    name = n;
    type = t;
    definition = d;
}

/*
 * Module: string getName() const
 * Functionality: Returns the name that is stored in Word object.
 * Input: None
 * Output: string - The name of the word
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 16.10.2026
 */
string Word::getName() const {
    return name;
}

/*
 * Module: string getType() const
 * Functionality: Returns the type that is stored in Word object.
 * Input: None
 * Output: string - The type of the word
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 16.10.2026
 */
string Word::getType() const {
    return type;
}

/*
 * Module: string getDefinition() const
 * Functionality: Returns the definition that is stored in the Word object.
 * Input: None
 * Output: string - The definition of the word
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 16.10.2026
 */
string Word::getDefinition() const {
    return definition;
}

/*
 * Module: void setName(const string& n)
 * Functionality: Assigns a new name to the Word object.
 * Input: n - The new name of the word
 * Output: None
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 16.10.2026
 */
void Word::setName(const string& n) {
    name = n;
}

/*
 * Module: void setType(const string& t)
 * Functionality: Assigns a new type to the Word object.
 * Input: t - The new type of the word
 * Output: None
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 16.10.2026
 */
void Word::setType(const string& t) {
    type = t;
}

/*
 * Module: void setDefinition(const string& d)
 * Functionality: Assigns a new definition to the Word object.
 * Input: d - The new definition of the word
 * Output: None
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 16.10.2026
 */
void Word::setDefinition(const string& d)
{
    definition = d;
}

/*
 * Module: string getFullType() const
 * Functionality: Converts the stored word type abbreviation to its full
 * word type.
 * Input: None
 * Output: string - The full word type
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 20.10.2026
 */
string Word::getFullType() const
{
    if (type == "n")
        return "noun";
    else if (type == "v")
        return "verb";
    else if (type == "adv")
        return "adverb";
    else if (type == "adj")
        return "adjective";
    else if (type == "prep")
        return "preposition";
    else if (type == "pn")
        return "proper noun";
    else if (type == "n_and_v")
        return "noun and verb";
    else if (type == "misc")
        return "miscellaneous";
    else
        return "unknown";
}

