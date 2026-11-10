/*
 * Dictionary Class Implementation - Assignment 2
 *
 * Purpose:
 * This file have the implemetation of the dictionary class functions this 
 * will load the dictionary records from text file and then it will store
 * whem as a word object in a vector
 *
 * Author: Adhil Ahamed (10739721)
 * Date: 20.10.2026
 */

#include "Dictionary.h"
#include <fstream>
#include <algorithm>
#include <cctype>

 /*
  * Module: Dictionary::Dictionary()
  * Functionality: There is a defualt constructer that will create a empty 
  * dictionary onject.
  * Input: None
  * Output: None
  *
  * Created by: Adhil Ahamed (10739721)
  * Date: 20.10.2026
  */
Dictionary::Dictionary() {
    // When the object is created the words vector is empty.
}

/*
 * Module: void Dictionary::menu()
 * Functionality: This function will display the dictionary menu and
 * then it allow the user to load the dictionary, search for a word,
 * view dictionary statistics, or exit the program.
 * 
 * Input: Menu choice entered by the user
 * Output: Displays the menu and the selected operation
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 20.10.2026
 */
void Dictionary::menu() {
    int choice;
    bool running = true;

    while (running) {
        cout << "\n===== Dictionary Menu =====" << endl;
        cout << "1. Load new Dictionary" << endl;
        cout << "2. Search for a Word" << endl;
        cout << "3. About Dictionary" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        string input;
        getline(cin, input);

        if (cin.eof()) {
            cout << "Input ended. Exiting dictionary." << endl;
            return;
        }
        if (input.length() != 1 || input[0] < '0' || input[0] > '9') {
            cout << "Invalid input: Please enter a single digit." << endl;
            continue;
        }
        choice = input[0] - '0';
        
        switch (choice) {
        case 1:
            loadDictionary("dictionary_2026S2.txt");
            break;
        case 2:
            searchWord();
            break;
        case 3:
            aboutDictionary();
            break;
        case 4:
            running = false;
            cout << "Exiting dictionary." << endl;
            break;
        default:
            cout << "Invalid choice: Please try again." << endl;
        }
    }
}

/*
 * Module: void Dictionary::loadDictionary(const string& filename)
 * Functionality: This will read the dictionary text file and the store
 * the valid word records as the word objectin the vector.
 * Input: filename - The name or path of the dictionary file
 * Output: Displays the number of loaded records or an error message
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 20.10.2026
 */
void Dictionary::loadDictionary(const string& filename) {
    // This will check whether the file has a .txt extension.
    if (filename.length() < 4 ||
        filename.substr(filename.length() - 4) != ".txt") {
        cout << "Error: Please select a valid .txt dictionary file." << endl;
        return;
    }

    // This checks weather the dictionary is already loaded.
    if (!words.empty()) {
        cout << "Dictionary is already loaded." << endl;
        return;
    }

    // This will open the dictionary text file.
    ifstream file(filename);

    // This will check the file opened successfully.
    if (!file.is_open()) {
        cout << "Error: Could not open dictionary file." << endl;
        return;
    }

    string line;
    string type;
    string name;
    string definition;

    // This reads the first line that contains the expected word cout.
    if (!getline(file, line)) {
        cout << "Error: Dictionary file is empty." << endl;
        return;
    }

    // This will read the balance lines in the dictionary file.
    while (getline(file, line)) {
        if (line == "---") {
            if (!getline(file, type) ||
                !getline(file, name) ||
                !getline(file, definition)) {
                cout << "Incomplete record found." << endl;
                break;
            }

            // This will check weather the word is valid.
            bool validType =
                type == "n" ||
                type == "v" ||
                type == "adv" ||
                type == "adj" ||
                type == "prep" ||
                type == "pn" ||
                type == "n_and_v" ||
                type == "misc";
            
            // This will store only records that has a valid information.
            if (validType && !name.empty() && !definition.empty()) {
                Word newWord(name, type, definition);
                words.push_back(newWord);
            }
            else {
                cout << "Invalid word record skipped." << endl;
            }
        }
    }
    // This will close the dictionary file.
    file.close();

    // This will display the actual number of the lodaed records
    cout << "Total records loaded: " << words.size() << endl;

    // This will check whether any valid dictionary records were loaded.
    if (words.empty()) {
        cout << "Error: No valid dictionary records found." << endl;
        return;
    }

    // This checks the expected number of words is loaded.
    if (words.size() == 105160) {
        cout << "Dictionary loaded successfully." << endl;
    }
    else {
        cout << "Warning: Dictionary record count is different "
            << "from the expected 105160 records." << endl;
    }
}

/*
 * Module: void Dictionary::searchWord()
 * Functionality: We use this to search for a word in the dictionary
 * without considering uppercase or lowercase letters. If the word
 * is found, this will display the word type and definitions separately.
 * Input: Word entered by the user
 * Output: Word details or a word not found message
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 20.10.2026
 */
void Dictionary::searchWord() {

    // This will check whether the dictionary is loaded.
    if (words.empty()) {
        cout << "Error: Dictionary is empty." << endl;
        return;
    }

    string searchTerm;
    cout << "\nEnter a word to search: ";
    getline(cin, searchTerm);

    // This will remove the spaces from the start and end of a word.
    size_t start = searchTerm.find_first_not_of(" \t");
    if (start != string::npos) {
        size_t end = searchTerm.find_last_not_of(" \t");
        searchTerm = searchTerm.substr(start, end - start + 1);
    }
    else {
        searchTerm.clear();
    }

    if (searchTerm.empty()) {
        cout << "Error: Please enter a word." << endl;
        return;
    }

    // This will convert the entered word to lowercase.
    transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);
    bool found = false;

    // This will search every word in the dictionary.
    for (const Word& word : words) {
        string wordName = word.getName();
        transform(wordName.begin(), wordName.end(), wordName.begin(), ::tolower);

        if (wordName == searchTerm) {
            found = true;
            string definition = word.getDefinition();
            string separator = ";  ";
            size_t position = 0;
            size_t start = 0;
            int definitionCount = 1;

            // Count the definitions.
            while ((position = definition.find(separator, start))
                != string::npos) {
                definitionCount++;
                start = position + separator.length();
            }

            cout << "\nWord Found - with "
                << definitionCount << " definitions" << endl;
            cout << "Word: " << word.getName() << endl;
            cout << "Type: (" << word.getFullType() << ")" << endl;

            // This will display each definition on separate line.
            start = 0;
            int number = 1;

            while ((position = definition.find(separator, start))
                != string::npos) {
                cout << number << ". "
                    << definition.substr(start, position - start)
                    << endl;
                number++;
                start = position + separator.length();
            }

            // This will display the final definition.
            cout << number << ". "
                << definition.substr(start) << endl;
            break;
        }
    }

    // This will display a message if a matching word is not found.
    if (!found) {
        cout << "word not found." << endl;
    }
}

/*
 * Module: void Dictionary::aboutDictionary()
 * Functionality: This function will display the statistics about the 
 * dictionary this will count the number of words for each word type
 * and the number of words starting with each letter and the number of
 * words for each word length.
 * 
 * Input: None
 * Output: Displays dictionary statistics on the screen
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 21.10.2026
 */
void Dictionary::aboutDictionary() {
    // This wil check weather the dictionary is loaded.
    if (words.empty()) {
        cout << "Error: Dictionary is empty." << endl;
        return;
    }
    int nounCount = 0;
    int verbCount = 0;
    int adverbCount = 0;
    int adjectiveCount = 0;
    int prepositionCount = 0;
    int properNounCount = 0;
    int nounVerbCount = 0;
    int miscellaneousCount = 0;

    // This array will store the number of words beginning with A to Z.
    int letterCount[26] = { 0 };

    // This will count the words beginning with a hyphen.
    int hyphenCount = 0;

    // This vector store the number of words for each word length.
    vector<int> lengthCount(1, 0);

    // This loop will go in every word in the dictionary.
    for (const Word& word : words) {
        string type = word.getType();
        string name = word.getName();

        if (type == "n") {
            nounCount++;
        }
        else if (type == "v") {
            verbCount++;
        }
        else if (type == "adv") {
            adverbCount++;
        }
        else if (type == "adj") {
            adjectiveCount++;
        }
        else if (type == "prep") {
            prepositionCount++;
        }
        else if (type == "pn") {
            properNounCount++;
        }
        else if (type == "n_and_v") {
            nounVerbCount++;
        }
        else if (type == "misc") {
            miscellaneousCount++;
        }

        // This will count the words begining with each letter.
        if (!name.empty()) {
            char firstLetter = name[0];
            if (firstLetter >= 'a' && firstLetter <= 'z') {
                letterCount[firstLetter - 'a']++;
            }
            else if (firstLetter == '-') {
                hyphenCount++;

            }

            // This will increse the vector size if the word is long.
            int wordLength = static_cast<int>(name.length());
            if (wordLength >= static_cast<int>(lengthCount.size())) {
                lengthCount.resize(wordLength + 1, 0);
            }
            lengthCount[wordLength]++;
        }
    }
    // This will display the total number of words.
    cout << "\n===== About Dictionary =====" << endl;
    cout << "Total words: " << words.size() << endl;

    // This will display the statistics of each word type
    cout << "\n--- Words by Type ---" << endl;
    cout << "Noun: " << nounCount << endl;
    cout << "Verb: " << verbCount << endl;
    cout << "Adverb: " << adverbCount << endl;
    cout << "Adjective: " << adjectiveCount << endl;
    cout << "Preposition: " << prepositionCount << endl;
    cout << "Proper Noun: " << properNounCount << endl;
    cout << "Noun and Verb: " << nounVerbCount << endl;
    cout << "Miscellaneous: " << miscellaneousCount << endl;

    // This will display the number of words starting with each letter
    cout << "\n--- Words by Starting Letter ---" << endl;
    cout << "Starting with hyphen (-): " << hyphenCount << endl;
    for (int i = 0; i < 26; i++) {
        char letter = static_cast <char>('A' + i);
        cout << letter << ": " << letterCount[i] << endl;
    }

    // This will display the number of words for each word length
    cout << "\n--- Words by Length ---" << endl;
    for (int i = 1; i < static_cast<int>(lengthCount.size()); i++) {
        cout << i << " letters: " << lengthCount[i] << endl;
    } 
}
