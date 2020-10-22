showPolTest: showPolTest.o showPol.o
	g++ showPolTest.o showPol.o -o showPol

showPolTest.o: showPolTest.cpp
	g++ -c showPolTest.cpp

showPol.o: showPol.cpp
	g++ -c showPol.cpp

clean:
	rm *.o showPolTest