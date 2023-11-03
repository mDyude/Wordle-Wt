/*
 * Copyright (C) 2008 Emweb bv, Herent, Belgium.
 *
 * See the LICENSE file for terms of use.
 */

#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include "WordSet.h"

/*
 * A simple hello world application class which demonstrates how to react
 * to events, read input, and give feed-back.
 */
class Wordle : public Wt::WApplication
{
public:
    Wordle(const Wt::WEnvironment &env);

private:
    Wt::WLineEdit *guessInput_;
    WordSet wSet;

    std::string answer_; // the answer word, randomly chosen from the txt file
    int guesses_; // the number of guesses, which cannot excess the 5 time limit
    char *ansCharArr;
    Wt::WText *top;
    Wt::WText *widgetArr[5];
    Wt::WText *correctArr[5];
    Wt::WPushButton *button;
    void click();
    void restartBut();
    void initializeWordle();
};