project: main.o Normalization.o IWavModel.o Echo.o Controller.o Console.o
	g++ -std=c++11 -o project main.o Normalization.o IWavModel.o Echo.o Controller.o Console.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Normalization.o: Normalization.cpp
	g++ -std=c++11 -c Normalization.cpp
IWavModel.o: IWavModel.cpp
	g++ -std=c++11 -c IWavModel.cpp
Echo.o: Echo.cpp
	g++ -std=c++11 -c Echo.cpp
Controller.o: Controller.cpp
	g++ -std=c++11 -c Controller.cpp
Console.o: Console.cpp
	g++ -std=c++11 -c Console.cpp	
clean:
	rm *.o 