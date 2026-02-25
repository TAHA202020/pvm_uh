#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include <pvm3.h>

int main() {
    point *pts;
    int mytid = pvm_mytid();  // THIS IS THE SLAVE'S TID
    printf("Slave running: TID=%d, points=%d\n", mytid, point_nb(pts));
    fflush(stdout);
    // receive points from master or parent
    pts = recv_points(PvmTaskDefault);

    // recursive call (may spawn two more slaves)
    upper_hull(pts);

    // send result back
    send_points(PvmTaskDefault, pts);

    point_free(pts);
    pvm_exit();
    return 0;
}