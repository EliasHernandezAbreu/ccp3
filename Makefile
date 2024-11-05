OUT=tm

build:
	mkdir -p ./bin
	g++ -o ./bin/${OUT} ./src/*.cpp
