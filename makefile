project: WaveHeader.o iWavModel.o WavManager.o Controller.o Console.o Processor.o main.cpp
	g++ -std=c++11 -o project WaveHeader.o iWavModel.o WavManager.o Controller.o Console.o Processor.o main.cpp
WaveHeader.o: WaveHeader.cpp WaveHeader.h
	g++ -c -std=c++11 WaveHeader.cpp
iWavModel.o: iWavModel.cpp iWavModel.h
	g++ -c -std=c++11 v.cpp
WavManager.o: WavManager.cpp WavManager.h
	g++ -c -std=c++11 WavManager.cpp
Controller.o: Controller.cpp Controller.h
	g++ -c -std=c++11 Controller.cpp
Console.o: Console.cpp Console.h
	g++ -c -std=c++11 Console.cpp
Processor.o: Processor.cpp Processor.h
	g++ -c -std=c++11 Processor.cpp
clean:
	rm *.o