CFLAGS = -Wall -Werror -Wformat=0 -fno-stack-protector
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

compile:
	mv main.cpp main
	g++ $(CFLAGS) -c *.cpp $(LIBS)
	mv main main.cpp
	ar rvs bug.a *.o
	rm *.o

install:
	cp bug.a libbug.a
	chmod 0644 *.h *.a
	chmod 0755 gpp
	sudo mkdir -p /usr/local/include
	sudo chmod 0755 /usr/local/include
	sudo cp *.h /usr/local/include
	sudo mkdir -p /usr/local/lib
	sudo chmod 0755 /usr/local/lib
	sudo cp libbug.a /usr/local/lib
	sudo mkdir -p /usr/local/bin
	sudo chmod 0755 /usr/local/bin
	sudo cp gpp /usr/local/bin
