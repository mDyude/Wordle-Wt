#include "WordSet.h"

// this is the class of the set that would store all the valid words
void WordSet::readFromFile(const std::string &path) {
    std::ifstream infile(path);
    std::string word;

    // insert words into the set 
    while (infile >> word) {
        words.insert(word);
    }

    infile.close();
    std::cout << "WordSet: file read successfullly" << std::endl;
}

// check if the word is in the set
bool WordSet::contains(const std::string &word) {
    return words.find(word) != words.end();
}

// print the set
void WordSet::display() {
    for (const std::string& word : words) {
        std::cout << word << ' ';
    }
    std::cout << std::endl;
}

// return a random word from the set
std::string WordSet::randomWord() {
    // generate a random number that is smaller than the size of the set
    srand(time(NULL));
    int r = rand() % words.size();

    // std::set<std::string>::iterator it;
    std::set<std::string>::const_iterator it(words.begin());
    advance(it, r);
    // at this moment, it is pointing to a random character 
    return *it;
}