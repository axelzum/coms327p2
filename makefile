all: parta

parta: main.cpp SoundSamples.cpp wave.cpp
	g++ -o main main.cpp SoundSamples.cpp wave.cpp -lm

clean:
	rm -f main *~
