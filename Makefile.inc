BUILD_DIRNAME=build
BUILDPATH=$(TOP)/$(BUILD_DIRNAME)/$(RELPATH)

INC = $(TOP)/src
CXXFLAGS=-g -Wall -std=c++11 -I$(INC)
src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

.PHONY: all clean

all: post-build

pre-build:
		 mkdir -p $(BUILDPATH)

post-build: main-build
	    @echo Done $(TARGET)

main-build: pre-build
	    @$(MAKE) --no-print-directory $(TARGET)

clean:
	rm -f $(BUILDPATH)/*
