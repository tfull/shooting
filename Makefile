compiler = g++
sources = Game Keyboard Main Extention
target = main
OS = ${shell uname -s}
ifeq ($(OS), Darwin)
options = -framework GLUT -framework OpenGL
endif
ifeq ($(OS), Linux)
libs = -lglut -lGLU -lGL -lm
endif

bin/$(target): $(addsuffix .o, $(addprefix bin/, $(sources)))
	$(compiler) $(options) -o $@ $^ $(libs)

bin/%.o: src/%.cpp
	$(compiler) $(options) -c -o $@ $< $(libs)

.PHONY: clean
clean:
	rm bin/*
