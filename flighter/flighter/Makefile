# run: objects

run: main.o
	@g++ main.o -o flighter_game -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio


main.o: main.cpp
	@g++ main.cpp -o main.o -c


clean:
	@rm -f *.o 

cleanall: clean
	@rm -f flighter_game
