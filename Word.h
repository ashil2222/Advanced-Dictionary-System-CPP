/*
 * Word Class - Assignment 2
 *
 * Purpose:
 * This class shows a single word in the dictionary.
 * this will store the word's name, type and definition as private
 * member variables it also give functions to access these properties.
 *
 * Author: Adhil Ahamed (10739721)
 * Date: 16.10.2026
 */
#ifndef WORD_H
#define WORD_H

#include <string>
using namespace std;

class Word {
private:
    // Private member variables
    string name;        // The name of the word
    string type;        // The type of the word
    string definition;  // The definition of the word
public:
    /*
     * Module: Word()
     * Functionality: Default constructor that initializes a empty Word object.
     * Input: None
     * Output: None
     *
     * Created by: Adhil Ahamed (10739721)
     * Date: 16.10.2026
     */
    Word();

    /*
     * Module: Word(string n, string t, string d)
     * Functionality: Parameterized constructor that initializes a 
     * word with the given values
     * Input:
     *   n - The name of the word
     *   t - The type of the word
     *   d - The definition of the word
     * Output: None
     *
     * Created by: Adhil Ahamed (10739721)
     * Date: 16.10.2026
     */

    Word(string n, string t, string d);
    /*
     * Module: string getName() const
     * Functionality: Gets the name of the word.
     * Input: None
     * Output: string - The name of the word
     *
     * Created by: Adhil Ahamed (10739721)
     * Date: 16.10.2026
     */
    string getName() const;

    /*
     * Module: string getType() const
     * Functionality: Gets the type of the word.
     * Input: None
     * Output: string - The type of the word
     *
     * Created by: Adhil Ahamed (10739721)
     * Date: 16.10.2026
     */
    string getType() const;

    /*
     * Module: string getDefinition() const
     * Functionality: Gets the definition of the word.
     * Input: None
     * Output: string - The definition of the word
     *
     * Created by: Adhil Ahamed (10739721)
     * Date: 16.10.2026
     */
    string getDefinition() const;

    /*
    * Module: void setName(const string& n)
    * Functionality: Sets the name of the word.
    * Input: n - The new name of the word
    * Output: None
    *
    * Created by: Adhil Ahamed (10739721)
    * Date: 16.10.2026
    */
    void setName(const string& n);

    /*
     * Module: void setType(const string& t)
     * Functionality: Updates the type of the word.
     * Input: t - The new type of the word
     * Output: None
     *
     * Created by: Adhil Ahamed (10739721)
     * Date: 16.10.2026
     */
    void setType(const string& t);

    /*
     * Module: void setDefinition(const string& d)
     * Functionality: Updates the definition of the word.
     * Input: d - The new definition of the word
     * Output: None
     *
     * Created by: Adhil Ahamed (10739721)
     * Date: 16.10.2026
     */
    void setDefinition(const string& d);

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
    string getFullType() const;
};

#endif // WORD_H




