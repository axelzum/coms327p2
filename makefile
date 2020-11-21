all: partb

partb: TestMain.cpp SoundSamples.cpp wave.cpp soundio.cpp
		g++ -o main TestMain.cpp SoundSamples.cpp wave.cpp soundio.cpp

parta: main.cpp SoundSamples.cpp wave.cpp soundio.cpp
	g++ -o main main.cpp SoundSamples.cpp wave.cpp soundio.cpp

clean:
	rm -f main *~
