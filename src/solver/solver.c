#include "solver.h"

#include "../day01/day01.h"
#include "../day02/day02.h"

Solver get_solver(int day) {
    Solver solver;

    switch(day) {
        case 1:
            solver.part_one = day01_part_one;
            solver.part_two = day01_part_two;
            break;
        case 2:
            solver.part_one = day02_part_one;
            solver.part_two = day02_part_two;
            break;
    }

    return solver;
}
