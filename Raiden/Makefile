# run: objects

run: main.o menu.o info.o game.o
	@g++ -w game.o info.o menu.o main.o -o Raiden -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio


dir: 

main.o: main.cpp
	@g++ -w main.cpp -o main.o -c

menu.o: menu.cpp
	@g++ -w menu.cpp -o menu.o -c

info.o: info.cpp
	@g++ -w info.cpp -o info.o -c

game.o: game.cpp
	@g++ -w game.cpp -o game.o -c

clean:
	@rm -rf *.o

remove: clean
	@rm -rf Raiden
