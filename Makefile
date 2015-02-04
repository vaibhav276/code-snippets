all: directories reverse-list sorted-merge

directories:
	mkdir -p obj/linked-lists/common
	mkdir -p target/dbg/linked-lists
	mkdir -p target/rel/linked-lists

reverse-list: lnode.o lmanager.o reverse-list.o
	g++ -g -Wall obj/linked-lists/common/lnode.o obj/linked-lists/common/lmanager.o obj/linked-lists/reverse-list.o -o target/dbg/linked-lists/reverse-list 
	
sorted-merge: lnode.o lmanager.o sorted-merge.o
	g++ -g -Wall obj/linked-lists/common/lnode.o obj/linked-lists/common/lmanager.o obj/linked-lists/sorted-merge.o -o target/dbg/linked-lists/sorted-merge
	
lnode.o:
	g++ -g -std=c++11 -c -Wall -I inc/ src/linked-lists/common/lnode.cpp -o obj/linked-lists/common/lnode.o
	
lmanager.o:
	g++ -g -std=c++11 -c -Wall -I inc/ src/linked-lists/common/lmanager.cpp -o obj/linked-lists/common/lmanager.o
	
reverse-list.o:
	g++ -g -std=c++11 -c -Wall -I inc/ src/linked-lists/reverse-list.cpp -o obj/linked-lists/reverse-list.o

sorted-merge.o:
	g++ -g -std=c++11 -c -Wall -I inc/ src/linked-lists/sorted-merge.cpp -o obj/linked-lists/sorted-merge.o
	
clean:
	rm -rf obj
	rm -rf target