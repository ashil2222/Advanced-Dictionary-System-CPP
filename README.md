# Advanced Dictionary System — C++17

A console-based dictionary application developed using C++17 and Object-Oriented Programming (OOP). The system provides dictionary searching, an interactive word guessing game, and intelligent spelling suggestions using three string similarity algorithms.

Developed as part of **CSP2104 — C++ Programming** coursework at Edith Cowan University.

## Features

### 1. Dictionary Loading
- Loads and processes 105,160 dictionary records from a text file.
- Stores words, definitions, and word types.

### 2. Word Search
- Search for words using case-insensitive matching.
- Displays definitions and word types.
- Handles invalid and empty search inputs.

### 3. Dictionary Information
- Displays information about the loaded dictionary.

### 4. Word Guessing Game
- Presents a definition, word type, first letter, and word length as clues.
- Starts with 5 lives.
- Awards 3 points for each correct guess.
- Awards an extra life for every 5 points earned.
- Ends when the player runs out of lives.

### 5. Smart Search
Suggests up to five similar words using each of three algorithms:

- **Hamming Distance** — Compares character differences between equal-length words.
- **Levenshtein Distance** — Measures insertions, deletions, and substitutions.
- **Damerau-Levenshtein Distance** — Also considers character transpositions.

## Technologies Used

- C++17
- Microsoft Visual Studio
- Standard Template Library (STL)
- Object-Oriented Programming (OOP)
- File handling and string processing

## Programming Concepts

- Classes and objects
- Inheritance and polymorphism
- Abstract classes and virtual functions
- Smart pointers (`unique_ptr`)
- Vectors and unordered sets
- Sorting and searching algorithms
- Input validation

## Project Structure

- `main.cpp` — Application entry point
- `Dictionary.cpp / .h` — Dictionary loading and searching
- `AdvancedDictionary.cpp / .h` — Guessing game and Smart Search
- `Word.cpp / .h` — Word data model
- `AlgorithmHelper.cpp / .h` — Random word selection helper
- `SimmilarityMeasure.cpp / .h` — String similarity algorithms
- `dictionary_2026S2.txt` — Dictionary dataset

## How to Run

1. Clone or download the repository.
2. Open the project in Visual Studio or another compatible C++ development environment.
3. Compile all `.cpp` files using C++17.
4. Ensure `dictionary_2026S2.txt` is in the program's working directory.
5. Run the program.
6. Select option 1 to load the dictionary before using the other features.

## Author

**Adhil Ahamed**

CSP2104 — C++ Programming  
Edith Cowan University
