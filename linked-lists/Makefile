all: reverse-list

reverse-list: liblnode.so liblmanager.so reverse-list.o
	g++ -Lobj -llnode -llmanager obj/reverse-list.o -o obj/reverse-list 
	
liblnode.so:
	g++ -std=c++11 -c src/common/lnode.cpp -o obj/liblnode.so
	
liblmanager.so:
	g++ -std=c++11 -shared -fPIC -c src/common/lmanager.cpp -o obj/liblmanager.so
	
reverse-list.o:
	g++ -std=c++11 -c src/reverse-list.cpp -o obj/reverse-list.o

#%: %.cpp
	#g++ -std=c++11 $< -o $@

