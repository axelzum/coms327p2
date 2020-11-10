all: parta

parta: main.cpp SoundSamples.cpp
	g++ -o main main.cpp SoundSamples.cpp

clean:
	rm -f main *~
