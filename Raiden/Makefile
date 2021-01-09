# run: objects

run: Raiden/main.o Raiden/menu.o Raiden/info.o Raiden/game.o
	@g++ game.o info.o menu.o main.o -o RGame -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio


dir:
	@if [ ! -d "obj" ]; then mkdir obj; fi

Raiden/main.o: Raiden/main.cpp
	@g++ -w Raiden/main.cpp -o main.o -c

Raiden/menu.o: Raiden/menu.cpp
	@g++ -w Raiden/menu.cpp -o menu.o -c

Raiden/info.o: Raiden/info.cpp
	@g++ -w Raiden/info.cpp -o info.o -c

Raiden/game.o: Raiden/game.cpp
	@g++ -w Raiden/game.cpp -o game.o -c

clean:
	@rm -rf *.o 

remove: clean
	@rm -rf RGame
