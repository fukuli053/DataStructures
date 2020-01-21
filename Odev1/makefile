hepsi:derle calistir
derle:
	g++ -I./include -c ./src/Kova.cpp -o ./lib/Kova.o
	g++ -I./include -c ./src/Top.cpp -o ./lib/Top.o
	g++ -I./include -c ./src/KovaKontrol.cpp -o ./lib/KovaKontrol.o
	g++ -I./include ./src/Test.cpp -o ./bin/Test ./lib/Kova.o ./lib/Top.o ./lib/KovaKontrol.o
calistir:
	./bin/Test