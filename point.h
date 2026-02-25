#ifndef POINT_H
#define POINT_H

#define XMAX 100000
#define YMAX 100000

typedef struct st_point point;
struct st_point {
    int x, y;
    point *next;
};

// point.c functions
extern point *point_alloc();
extern void point_free(point *pts);
extern void point_print_gnuplot(point *pts, int solid);
extern point *point_random(int nbPts);
extern point *point_UH(point *pts);
extern int point_nb(point *pts);
extern point *point_part(point *pts);
extern point *point_merge_UH(point *pts1, point *pts2);

// send/recv helpers
extern void send_points(int tid, point *pts);
extern point *recv_points(int tid);

// recursive convex hull
extern void upper_hull(point *pts);

#endif