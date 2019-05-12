Resultados_hw2.pdf: Resultados_hw2.tex	Plots_hw2.pdf
	pdflatex Resultados_hw2.tex

Plots_hw2.pdf: Plots_hw2.py	signal.dat
	python Fourier.py

DATOS.dat: a.out edificio.cpp
	g++ edificio.cpp
	./a.out >> DATOS.dat
