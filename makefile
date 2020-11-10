all: parta

parta: main.cpp SoundSamples.cpp wave.cpp soundio.cpp
	g++ -o main main.cpp SoundSamples.cpp wave.cpp soundio.cpp

clean:
	rm -f main *~
