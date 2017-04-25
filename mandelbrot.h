#include <stdlib.h>

/*
 mandelbrot - returns the array of points of requested resolution (ncolumns*nrows)
 Every point is an integer representation of "color" or the 1/speed of sequence infinity run-out
*/
int ** mandelbrot(size_t ncolumns, size_t nrows, double center_p, double center_q, double pwidth, double qwidth, int depth) {
    int **array;
    array = malloc(nrows * sizeof(int *));

    double Pmin = center_p - pwidth;
    double Pmax = center_p + pwidth;
    double Qmin = center_q - qwidth;
    double Qmax = center_q + qwidth;

    double Pstep = (Pmax - Pmin)/ncolumns;
    double Qstep = (Qmax - Qmin)/nrows;

    double Cr, Ci, Zr, Zi, tmp;
    int k;

    for (int i = 0; i < nrows; i++) {
	Ci = Qmin + i * Qstep;
        array[i] = malloc(ncolumns * sizeof(int));

	for (int j = 0; j < ncolumns; j++) {
		array[i][j] = 0;
		Cr = Pmin + j * Pstep;
		Zi = Zr = 0;
		for (k = 0; k < depth; k++) {
			tmp = Zr * Zr - Zi * Zi + Cr;
			Zi = 2 * Zr * Zi + Ci;
			Zr = tmp;
			if (Zr * Zr + Zi * Zi > 4) break;
		}
		if (k < depth) {
			array[i][j] = k;
       		}
	}
    }
    return array;
}
