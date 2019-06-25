#ifndef SOLVER_H
#define SOLVER_H

typedef struct _solver {
    char * (* part_one)(char * input);
    char * (* part_two)(char * input);
} Solver;

Solver get_solver(int day);

#endif
