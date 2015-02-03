all: reverse-list

reverse-list: lnode.o lmanager.o reverse-list.o
	g++ -Wall obj/lnode.o obj/lmanager.o obj/reverse-list.o -o obj/reverse-list 
	
lnode.o:
	g++ -std=c++11 -c -Wall src/common/lnode.cpp -o obj/lnode.o
	
lmanager.o:
	g++ -std=c++11 -c -Wall src/common/lmanager.cpp -o obj/lmanager.o
	
reverse-list.o:
	g++ -std=c++11 -c -Wall src/reverse-list.cpp -o obj/reverse-list.o
