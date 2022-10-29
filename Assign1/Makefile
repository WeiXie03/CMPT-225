all: DQtest DQarraytest


DQarraytest: DQarraytest.o # test program for Deque class overloaded [] operator
	g++ -Wall -o DQarraytest DQarraytest.o  

DQtest: DQtest.o  # test program for Deque class
	g++ -Wall -o DQtest DQtest.o  


#DQtest.o: DQtest.cpp Deque.h Deque.cpp dsexceptions.h
DQtest.o: DQtest.cpp Deque.h dsexceptions.h
	g++ -Wall -o DQtest.o -c DQtest.cpp

DQarraytest.o: DQarraytest.cpp Deque.h dsexceptions.h # test program for Deque class overloaded [] operator
	g++ -Wall -o DQarraytest.o -c DQarraytest.cpp

clean:
	rm -f DQtest DQarraytest *.o
