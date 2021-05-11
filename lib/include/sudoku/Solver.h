#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

#include "Grid.h"

namespace sudoku
{

enum Level
{
    LEV_0_LOGIC,
    LEV_1_LOGIC,
    LEV_2_LOGIC,
    LEV_3_GUESS,
    LEV_UNKNOWN
};

namespace solver
{

namespace techniques
{

bool nakedSingles(Grid &pGrid, Logs *logs = nullptr, bool *check = nullptr);
bool hiddenSingles(Grid &pGrid, Logs *logs = nullptr);
bool lockedCandidates(Grid &pGrid, Logs *logs = nullptr);
bool xWings(Grid &pGrid, Logs *logs = nullptr); // basicFish with size=2 does the same job, but this is more efficient.
bool xyWing(Grid &pGrid, Logs *logs = nullptr);
bool basicFish(Grid &pGrid, BasicFishType fishType, Logs *logs = nullptr);
bool hiddenMulti(Grid &pGrid, HiddenMultiType multiType, Logs *logs = nullptr);
bool nakedMulti(Grid &pGrid, NakedMultiType multiType, Logs *logs = nullptr);

} // namespace techniques

Level solveLevel(Grid &pGrid, Logs *logs = nullptr, Level maxLevel = LEV_3_GUESS);
int solveByGuesses(Grid &pGrid, int maxSolutions = 1);

} // namespace solver

} // namespace sudoku

#endif // SUDOKU_SOLVER_H
