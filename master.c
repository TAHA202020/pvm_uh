#include "stdio.h"
#include "stdlib.h"
#include "point.h"
#include <pvm3.h>

int main(int argc, char **argv) {
    point *pts;
    // début du chronomètre dès le lancement
    if(argc != 2) {
        fprintf(stderr,"Usage: %s <nb points>\n", argv[0]);
        exit(1);
    }
    pts = point_random(atoi(argv[1]));
    point_print_gnuplot(pts, 0);  // affichage des points
    // calcul de l'enveloppe convexe
    upper_hull(pts);
    point_print_gnuplot(pts, 1);  // affichage de l'enveloppe
    point_free(pts);
    pvm_exit();
    return 0;
}