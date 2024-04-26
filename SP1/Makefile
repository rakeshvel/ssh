p1: p1.o libsparrow.so
	g++ p1.o -lsparrow -L. -o p1

p1.o: p1.cpp sparrow.h
	g++ -c p1.cpp

p2: p2.o libsparrow.so
	g++ p2.o -lsparrow -L. -o p2

p2.o: p2.cpp sparrow.h
	g++ -c p2.cpp

p3: p3.o libsparrow.so
	g++ p3.o -lsparrow -L. -o p3

p3.o: p3.cpp sparrow.h
	g++ -c p3.cpp

p4: p4.o libsparrow.so
	g++ p4.o -lsparrow -L. -o p4

p4.o: p4.cpp sparrow.h
	g++ -c p4.cpp

libsparrow.so: sparrow.o
	g++ sparrow.o -shared -o libsparrow.so

sparrow.o: sparrow.cpp sparrow.h
	g++ -c sparrow.cpp -fPIC
