A Wordle web app utilizing Wt framework, written in C++

If linker error is occured, try changing line 8 of Makefile as follows:
LDFLAGS=-L$(WT_BASE)/lib -Wl,-rpath,$(WT_BASE)/lib -lwthttp -lwt -lboost_thread -lboost_atomic -lboost_filesystem

To run the program (after it has been compiled): ```./wordle --docroot . --http-listen 0.0.0.0:8080``` 
Or use your desired IP/port cobination.
