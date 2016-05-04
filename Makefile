compiler = g++-5
sources = Game Keyboard Main
target = main
options = -framework GLUT -framework OpenGL

bin/$(target): $(addsuffix .o, $(addprefix bin/, $(sources)))
	$(compiler) $(options) -o $@ $^

bin/%.o: src/%.cpp
	$(compiler) $(options) -c -o $@ $<

.PHONY: clean
clean:
	rm bin/*
