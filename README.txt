This assignment is partially based on the "hello world" sample code. I hope it is not considered plagiarism.

The code should run perfectly, and pass all the requirements specified in the assignment instruction.

The Makefile is modified by removing boosted linkers. If linker error is occured, try change the line 8 of Makefile back, as follows:
LDFLAGS=-L$(WT_BASE)/lib -Wl,-rpath,$(WT_BASE)/lib -lwthttp -lwt -lboost_thread -lboost_atomic -lboost_filesystem

The program was developed and tested on a M1 Macbook.




The program will first read all the valid Wordle words from the "valid-wordle-words.txt" that I foudn online (though it's not that valid. I have encountered random answers from this file like "mmkay". Unless it is in the South Park universe, there's no way that's an actual word).
Then those words will be stored in a set. After that the a random word will be chosen from the set.

Then it's just regular stuff, I don;t even know where to start with.

The program will store the user input, determine if it is a valid word by searching the word set. If it is not a valid word, the answer will not be accepted; if it is, the program will then compare it with the answer using basic nested for loops.

If the answer submitted is right, or the maximum attemps are exceeded, the "Submit" button will be changed to a "Restart" button that will restart the game, by clearing the root()
