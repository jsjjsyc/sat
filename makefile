sat:main.o cnf.o
	g++ main.o cnf.o -o sat

main.o:main.cpp cnf.h
	g++ -c main.cpp

cnf.o:cnf.cpp cnf.h
	g++ -c cnf.cpp

clean:
	-rm *.o
	-rm sat
