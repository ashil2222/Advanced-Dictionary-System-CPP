/*
 * AdvancedDictionary Class Implementation - Assignment 2
 *
 * Purpose:
 * This file has the implemetation of the AdvanceDictionary class function 
 * this will provide a advance menu with additional features like Guessing
 * gmae and smart search.
 *
 * Author: Adhil Ahamed (10739721)
 * Date: 22.10.2026
 */

#include "AdvancedDictionary.h"
#include "SimmilarityMeasure.h"
#include "AlgorithmHelper.h"
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_set>

 /*
 * Module: AdvancedDictionary()
 * Functionality: This will create the three similarity algoritham the 
 * objects used by the smart search function.
 *
 * Input: None
 * Output: Initializes the similarity measures.
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 23.10.2026
 */
AdvancedDictionary::AdvancedDictionary() {
    measures.push_back(make_unique<HammingDistance>());
    measures.push_back(make_unique<LevenshteinDistance>());
    measures.push_back(make_unique<DamerauLevenshteinDistance>());
}

/*
 * Module: void AdvancedDictionary::menu()
 * Functionality: This function will display the advance dictionary menu
 * and allows the user to select the available operations.
 * 
 * Input: Menu choice entered by the user
 * Output: Displays the menu and the selected operation
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 22.10.2026
 */
void AdvancedDictionary::menu() {
    const string DICTIONARY_FILE = "dictionary_2026S2.txt";
    int choice;
    bool running = true;

    while (running) {
        cout << "\n===== Advanced Dictionary Menu =====" << endl;
        cout << "1. Load new Dictionary" << endl;
        cout << "2. Search for a Word" << endl;
        cout << "3. About Dictionary" << endl;
        cout << "4. Guessing Game" << endl;
        cout << "5. Smart Search" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        // This will check whether the entered input is a number.
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

        switch(choice) {
        case 1:
            loadDictionary(DICTIONARY_FILE);
            break;
        case 2:
            searchWord();
            break;
        case 3:
            aboutDictionary();
            break;
        case 4:
            guessingGame();
            break;
        case 5:
            smartSearch();
            break;
        case 6:
            running = false;
            cout << "Exiting dictionary." << endl;
            break;
        default:
            cout << "Invalid choice: Please try again." << endl;
        }
    }
}

/*
 * Module: void AdvancedDictionary::guessingGame()
 * Functionality: This function will run the word guessing gameby using random
 * words from the loaded dictionary this will display the hints and allow the
 * user to earn points and extra life by gusseing correctly.
 * 
 * Input: Word guesses entered by the user
 * Output: Displays the game information
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 22.10.2026
 */
void AdvancedDictionary::guessingGame() {
    // This will check whether the dictionary is loaded.
    if (words.empty()) {
        cout << "Error: Dictionary is empty." << endl;
        return;
    }
    // Check whether the dictionary contains an eligible word.
        bool hasEligibleWord = false;

    for (const Word& word : words) {
        if (word.getName().length() >= 3 &&
            word.getName().find('-') == string::npos) {
            hasEligibleWord = true;
            break;
        }
    }
    if (!hasEligibleWord) {
        cout << "Error: No eligible words for the guessing game." << endl;
        return;
    }

    int lives = 5;
    int points = 0;
    int nextExtraLife = 5;

    // This will initialize the random number generator once.
    static bool randomInitialized = false;

    if (!randomInitialized) {
        srand(static_cast<unsigned int>(time(0)));
        randomInitialized = true;
    }

    cout << "\n===== Guessing Game =====" << endl;
    cout << "Starting lives: " << lives << endl;
    cout << "Starting points: " << points << endl;

    // The game continues when the player has lives.
    while (lives > 0) {
        int randomIndex = -1;

        // Find a word that have at least three letters and havent a hyphen
        do {
            randomIndex = AlgorithmHelper::getRandomIndex(
                static_cast<int>(words.size()) - 1);
            if (randomIndex == -1) {
                cout << "Error: Could not select a word." << endl;
                return;
            }
        } while (words[randomIndex].getName().length() < 3 ||
            words[randomIndex].getName().find('-') != string::npos);
        Word selectedWord = words[randomIndex];
        string answer = selectedWord.getName();
        string guess;

        // This will display the hints to the selected word.
        cout << "\n----- New Word -----" << endl;
        cout << "Definition: " << selectedWord.getDefinition() << endl;
        cout << "Word type: " << selectedWord.getFullType() << endl;
        cout << "First letter: " << answer[0] << endl;
        cout << "Word length: " << answer.length() << endl;
        cout << "\nLives: " << lives << endl;
        cout << "Points: " << points << endl;
        cout << "Enter your guess: ";

        if (!getline(cin, guess)) {
            cout << "Input ended. Returning to the menu." << endl;
            return;
        }

        // This will remove the spaces from the start and end of a word.
        size_t start = guess.find_first_not_of(" \t");
        if (start != string::npos) {
            size_t end = guess.find_last_not_of(" \t");
            guess = guess.substr(start, end - start + 1);
        }
        else {
            guess.clear();
        }

        // This converts the guess to lowercase
        transform(guess.begin(), guess.end(),
            guess.begin(), [](unsigned char c) {
                return static_cast<char>(tolower(c));
            });

        // This will check the guess matches of the selected word
        if (guess == answer) {
            points += 3;
            cout << "Correct answer!" << endl;
            cout << "You earned 3 points." << endl;

            // Award one extra life for each five point threshold reached.
            while (points >= nextExtraLife) {
                lives++;
                nextExtraLife += 5;
                cout << "You earned an extra life!" << endl;
            }
        }
        else {
            lives--;
            cout << "Incorrect answer." << endl;
            cout << "The correct word was: " << answer << endl;
            cout << "You lost 1 life." << endl;
        }
        cout << "Current points: " << points << endl;
        cout << "Remaining lives: " << lives << endl;
    }
    cout << "\n===== Game Over =====" << endl;
    cout << "Final score: " << points << endl;
}

/*
 * Module: AdvancedDictionary::smartSearch()
 * Functionality: The searches to the five closest dictionary the words 
 * used Hamming, Levenshtein and Damerau-Levenshtein distance algorithms.
 *
 * Input: A word entered by the user.
 * Output: Five closest matching words for each algorithm including
 *         their distances.
 *
 * Created by: Adhil Ahamed (10739721)
 * Date: 23.10.2026
 */
void AdvancedDictionary::smartSearch() {
    if (words.empty()) {
        cout << "Error: Dictionary is empty." << endl;
        return;
    }
    string searchWord;
    cout << "Enter a word: ";
    getline(cin, searchWord);

    // This will remove the spaces from the start and end of a word.
    size_t start = searchWord.find_first_not_of(" \t");
    if (start != string::npos) {
        size_t end = searchWord.find_last_not_of(" \t");
        searchWord = searchWord.substr(start, end - start + 1);
    }
    else {
        searchWord.clear();
    }

    if (searchWord.empty()) {
        cout << "Error: Please enter a word." << endl;
        return;
    }
    transform(searchWord.begin(), searchWord.end(),
        searchWord.begin(), [](unsigned char c) {
            return static_cast<char>(tolower(c));
        });

    // This will compare the words in dictionary using smilarity algorithm.
    for (const auto& measure : measures) {
        vector<pair<int, string>> results;
        unordered_set<string> seenWords;
        for (const Word& word : words) {
            string dictionaryWord = word.getName();
            transform(dictionaryWord.begin(), dictionaryWord.end(),
                dictionaryWord.begin(), [](unsigned char c) {
                    return static_cast<char>(tolower(c));
                });
         
            if (dictionaryWord == searchWord) {
                continue;
            }
            if (!seenWords.insert(dictionaryWord).second) {
                continue;
            }
            int distance = measure->calculateDistance(
                searchWord, dictionaryWord);
            if (distance == -1) {
                continue;
            }
            results.push_back(make_pair(distance, word.getName()));
        }

        sort(results.begin(), results.end());
        cout << "\n----- " << measure->getName() << " -----" << endl;

        if (results.empty()) {
            cout << "No matching words found." << endl;
            continue;
        }
        int resultCount = min(5, static_cast<int>(results.size()));
        for (int i = 0; i < resultCount; i++) {
            cout << i + 1 << ". " << results[i].second
                << " (Distance: " << results[i].first << ")"
                << endl;
        }
    }
}



