CXX=g++
BIN=Game
# we need -Wno-deprecated because otherwise macOS spits out a bunch of deprecation errors
CXXFLAGS=-framework GLUT -framework OpenGL -framework Cocoa -std=c++14 -o $(BIN) -Wno-deprecated -march=native
CXXINPUT=$(subst .cpp,.o,$(wildcard *.cpp))

all: $(CXXINPUT)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $<

clean:
	rm -rf *.o
	rm -rf $(BIN)
