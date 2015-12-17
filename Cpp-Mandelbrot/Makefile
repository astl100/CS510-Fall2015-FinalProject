LDLIBS=-lm
all: mandelbrot

mandelbrot: julia.o cplane.o

run: all
	./mandelbrot
	
clean: 
	rm -f mandelbrot julia.o cplane.o
