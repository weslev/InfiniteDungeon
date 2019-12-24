make:
	g++ -Wall -std=c++11 *.cpp -o infiniteDungeon
run:
	make
	./infiniteDungeon
clean:
	rm infiniteDungeon