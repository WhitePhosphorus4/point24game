point24:main.o getOrder.o calculate.o judge.o
	g++ main.o getOrder.o calculate.o judge.o -o point24

main.o:main.cpp inc.h 
	g++ -c main.cpp -o main.o
	# cc -c main.cpp

getOrder.o:getOrder.cpp inc.h calculate.o
	g++ -c getOrder.cpp -o getOrder.o
	# cc -c getOrder.cpp

calculate.o:calculate.cpp inc.h 
	g++ -c calculate.cpp -o calculate.o
	# cc -c calculate.cpp

judge.o:judge.cpp inc.h
	g++ -c judge.cpp -o judge.o
	# cc -c judge.cpp

clean:
	rm *.o