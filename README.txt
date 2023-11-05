A Wordle web app utilizing Wt framework, written in C++

If linker error is occured, try changing line 8 of Makefile as follows:
LDFLAGS=-L$(WT_BASE)/lib -Wl,-rpath,$(WT_BASE)/lib -lwthttp -lwt -lboost_thread -lboost_atomic -lboost_filesystem
