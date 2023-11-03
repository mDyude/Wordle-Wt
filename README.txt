A Wordle webapp utilizing Wt framework

The Makefile is modified by removing boosted linkers. If linker error is occured, try change the line 8 of Makefile back, as follows:
LDFLAGS=-L$(WT_BASE)/lib -Wl,-rpath,$(WT_BASE)/lib -lwthttp -lwt -lboost_thread -lboost_atomic -lboost_filesystem
