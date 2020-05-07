point24:main.o getOrder.o computer.o isOk.o
	g++ main.o getOrder.o computer.o isOk.o -o point24

main.o:main.cpp inc.h 
	g++ -c main.cpp -o main.o
	# cc -c main.cpp

getOrder.o:getOrder.cpp inc.h computer.o
	g++ -c getOrder.cpp -o getOrder.o
	# cc -c getOrder.cpp

computer.o:computer.cpp inc.h 
	g++ -c computer.cpp -o computer.o
	# cc -c computer.cpp

isOk.o:isOk.cpp inc.h
	g++ -c isOk.cpp -o isOk.o
	# cc -c isOk.cpp

clean:
	rm *.o