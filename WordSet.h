#include <iostream>
#include <fstream>
#include <string>
#include <set>

class WordSet {
private:
    std::set<std::string> words;
public:
    void readFromFile(const std::string& path);
    bool contains(const std::string& word);
    void display();
    std::string randomWord();
};