#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include "Wordle.h"


Wordle::Wordle(const Wt::WEnvironment &env) : WApplication(env) {  
    setTitle("Wordle"); // application title
    std::string path = "./valid-wordle-words.txt";
    // store the txt word file into the set
    wSet.readFromFile(path);

    initializeWordle();
}

// the function for printing the result
void Wordle::click() {
    const Wt::WString str = guessInput_->text();
    // convert WString to an actual std::string
    std::string utf8Str = str.toUTF8();
    // // to make the string case insensitive
    // utf8Str = std::tolower(utf8Str);
    std::string lowerUtf8Str;
    char* lowerUtf8Char = new char[6];
    char* utf8Char = new char[6];
    strcpy(utf8Char, utf8Str.c_str());
    for (int i = 0; i < 5; i ++) {
        lowerUtf8Char[i] = std::tolower(utf8Str[i]);
    }

    std::cout << "lower utf8 char:" << lowerUtf8Char <<std::endl;
    if (guesses_ < 6) {
        for (int i = 0; i < 5; i ++) {
            widgetArr[i] = root()->addWidget(std::make_unique<Wt::WText>());
        }
        // if the word set does include the input word,
        // it means the input string is indeed a valid word
        if (wSet.contains(lowerUtf8Char) && utf8Str.size() == 5) {
            guesses_ ++;
            // initialize the char array
            // it is a valid word, continue checking if it is the answer
            char *charArr = new char[6];
            // copy the string to the char array
            strcpy(charArr, lowerUtf8Char);
            std::cout << "the string of the input " << lowerUtf8Char << std::endl; 
            if (lowerUtf8Char == answer_) {
                // the answer is correct
                // print 5 letters with GREEN color
                for (int i = 0; i < 5; i ++) {
                    correctArr[i] = root()->addWidget(std::make_unique<Wt::WText>());
                }
                // text->setText(str);

                // i have to use this method to print the char out individually
                // because c++ doesn't seem to support uppercase utf8 strings transforms????
                // or maybe there's something wrong with my WString function???
                // i don't know it works for now
                for (int i = 0; i < 5; i ++) {
                    Wt::WString upperStr = Wt::WString(std::string(1, std::toupper(charArr[i])));
                    Wt::WString temp1 = Wt::WString(std::string("<span style='color: green;'>"));
                    Wt::WString temp2 = Wt::WString(std::string("</span>"));
                    correctArr[i]->setText(temp1 + upperStr + temp2);
                }
                root()->addWidget(std::make_unique<Wt::WBreak>());
                std::cout << "The answer is correct." << std::endl;
                top->setText("The answer is correct. Start a new game? ");
                guesses_ = 100;
                button->setText("Restart");
                button->clicked().connect(this, &Wordle::restartBut);
            }
            else {
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        // convert the current char to WString
                        Wt::WString wsChar = Wt::WString(std::string(1, std::toupper(charArr[i])));
                        
                        // the current char matches the answer at the same position
                        // green
                        if (charArr[i] == ansCharArr[j] && i == j) {
                            Wt::WString tempG1 = Wt::WString(std::string("<span style='color: green;'>"));
                            Wt::WString tempG2 = Wt::WString(std::string("</span>"));
                            widgetArr[i]->setText(tempG1 + wsChar + tempG2);
                            break;
                        }
                        // the current char is a in the string but in a different position
                        // red
                        else if (charArr[i] == ansCharArr[j] && i != j) {
                            Wt::WString tempR1 = Wt::WString(std::string("<span style='color: red;'>"));
                            Wt::WString tempR2 = Wt::WString(std::string("</span>"));
                            widgetArr[i]->setText(tempR1 + wsChar + tempR2);
                            break;
                        }
                        // the current char is not in the string
                        // gray
                        Wt::WString tempGr1 = Wt::WString(std::string("<span style='color: gray;'>"));
                        Wt::WString tempGr2 = Wt::WString(std::string("</span>"));    
                        widgetArr[i]->setText(tempGr1 + wsChar + tempGr2);
                        
                    } 
                }
                root()->addWidget(std::make_unique<Wt::WBreak>());
            }
            // the input is not a valid word
        }
        else {
            std::cerr << "Invalid word. Try again." << std::endl;
            top->setText("Invalid word. Try again. ");
        }
    } else {
        std::cerr << "Maximum tries (6) reached." << std::endl;
        top->setText("Maximum tries (6) reached. The answer is: " + answer_ + ". ");
        button->setText("Restart");
        button->clicked().connect(this, &Wordle::restartBut);

    } 
}

void Wordle::restartBut() {
    root()->clear();
    initializeWordle();
}

void Wordle::initializeWordle () {
    // a random answer will be selected from the set
    answer_ = wSet.randomWord();
    // std::cout << "1" << std::endl;

    ansCharArr = new char[6];
    strcpy(ansCharArr, answer_.c_str());
    std::cout << "the answer is " << answer_ << std::endl;

    guesses_ = 0;

    top = root()->addWidget(std::make_unique<Wt::WText>()); // show some text
    top->setText("Enter guesses.");

    guessInput_ = root()->addWidget(std::make_unique<Wt::WLineEdit>()); // allow text input
    guessInput_->setFocus();                                            // give focus

    button = root()->addWidget(std::make_unique<Wt::WPushButton>());
    button->setText("Submit.");
    // create a button
    button->setMargin(5, Wt::Side::Left); // add 5 pixels margin

    root()->addWidget(std::make_unique<Wt::WBreak>()); // insert a line break

    // the action of a click
    button->clicked().connect(this, &Wordle::click);

    guessInput_->enterPressed().connect(std::bind(&Wordle::click, this));

}