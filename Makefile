CXXFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic

__start__: ./test_wektora
	./test_wektora

obj:
	mkdir -p obj

./test_wektora: obj obj/main.o obj/LZespolona.o obj/Macierz.o obj/UkladRownanLiniowych.o
	g++ -o ./test_wektora obj/main.o obj/LZespolona.o obj/Macierz.o obj/UkladRownanLiniowych.o

obj/main.o: src/main.cpp inc/Wektor.hh inc/LZespolona.hh inc/Macierz.hh inc/UkladRownanLiniowych.hh inc/rozmiar.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp


obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh inc/rozmiar.hh
	g++ -c ${CXXFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

obj/Macierz.o:  inc/Macierz.hh inc/rozmiar.hh
	g++ -c ${CXXFLAGS} -o obj/Macierz.o 

obj/UkladRownanLiniowych.o:  inc/UkladRownanLiniowych.hh inc/rozmiar.hh
	g++ -c ${CXXFLAGS} -o obj/UkladRownanLiniowych.o 
