
all: 
	cd build; ninja;
cmake:
	cmake . -B build -G Ninja;
run:
	cd bin; ./app;
