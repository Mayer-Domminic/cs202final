project: main.o wavManager.o iWavModel.o waveManager Controller.o Console.o
	g++ -std=c++11 -o project main.o wavManager.o iWavModel.o waveManager.o Controller.o Console.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
wavManager.o: WavManager.h
	g++ -std=c++11 -c WavManager.h
iWavModel.o: iWavModel.cpp
	g++ -std=c++11 -c iWavModel.cpp
waveManager.o: WaveHeader.h
	g++ -std=c++11 -c WaveHeader.h
Controller.o: Controller.cpp
	g++ -std=c++11 -c Controller.cpp
Console.o: Console.cpp
	g++ -std=c++11 -c Console.cpp	
clean:
	rm *.o 