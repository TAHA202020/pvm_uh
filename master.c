/* TP algorithmique parallele
 * maitrise
 * LL
 * 13/03/2018
 * utilise gnuplot au lieu de jgraph
 */

/*
 * upper.c
 *
 * programme principal en sequentiel
 */

 #include "stdio.h"
 #include "stdlib.h"
 #include "point.h"
 #include <pvm3.h>
 
 /*
  * calcul recursif d'enveloppe
  * convexe par bissection
  */
 
 
 /*
  * upper <nb points>
  * exemple :
  * % upper 200 
  * % evince upper_hull.pdf
  */
 int main(int argc, char **argv) {
     point *pts;
 
     if(argc != 2) {
         fprintf(stderr,"Usage: %s <nb points>\n", argv[0]);
         exit(1);
     }
 
     pts = point_random(atoi(argv[1]));
 
     point_print_gnuplot(pts, 0);  // show points
 
     // fully parallel recursive computation
     upper_hull(pts);
 
     point_print_gnuplot(pts, 1);  // show convex hull
 
     point_free(pts);
     pvm_exit();
     return 0;
 }