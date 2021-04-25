#include "sudoku/Solver.h"
#include <iostream>
#include <sstream>

using namespace sudoku;

void printMsg(const std::string &puzzle, const std::string &msg)
{
    std::cout << std::endl;
    std::cout << std::string(9 * 9, '*') << std::endl;
    std::cout << puzzle << std::endl << msg << std::endl;
    std::cout << std::string(9 * 9, '*') << std::endl;
    std::cout << std::endl;
}

bool test(const std::string &puzzle, const std::string &notes, const std::string &expectedNotes)
{
    Grid grid;
    grid.fillValues(puzzle);
    grid.fillNotes(notes);

    Solver::reduceCandidatesByXWing(grid);

    Grid gridExpectedNotes;
    gridExpectedNotes.fillNotes(expectedNotes);
    if (!grid.compareNotes(gridExpectedNotes))
    {
        std::cout << std::string(9 * 9, '*') << std::endl;
        std::cout << "The notes don't match the expected notes." << std::endl;
        std::cout << "Actual:" << std::endl;
        grid.dump(Grid::D_NOTES);
        std::cout << "Expected:" << std::endl;
        gridExpectedNotes.dump(Grid::D_NOTES);
        std::cout << std::string(9 * 9, '*') << std::endl;
        return false;
    }

    return true;
}

int main(int, char **)
{
    if (!test("8.......5.16...79..9.4.1.3...25.96......3......18.79...4.7.8.1..68...37.9.......8",
            R"(
                .........|.23...7..|.........|  .23..6..9|.2...67.9|.23..6...|  .........|.2...6...|.........|
                .23.5....|.........|.........|  .23......|.........|.23.5....|  .........|.........|.........|
                .2..5.7..|.........|....5.7..|  .........|.2..567..|.........|  .........|.........|.2...6...|

                ..34..7..|..3...78.|.........|  .........|1..4.....|.........|  .........|...4...8.|1.....7..|
                ...4.67..|......78.|.........|  12...6...|.........|.2.4.6...|  .2.45....|.2.45..8.|1.....7..|
                ...4.6...|.........|.........|  .........|.2.4.6...|.........|  .........|.2.4.....|.........|

                .2..5....|.........|.........|  .........|.....6..9|.........|  .2..5....|.........|.....6..9|
                .........|.........|.........|  .2......9|...45....|...45....|  .........|.........|.2......9|
                .........|.2....7..|....5.7..|  123..6...|12...6...|.23..6...|  .2.45....|.2.456...|.........|
            )",
            R"(
                .........|.23...7..|.........|  .23..6..9|.2....7.9|.23..6...|  .........|.2...6...|.........|
                .23.5....|.........|.........|  .23......|.........|.23.5....|  .........|.........|.........|
                .2..5.7..|.........|....5.7..|  .........|.2..567..|.........|  .........|.........|.2...6...|

                ..34..7..|..3...78.|.........|  .........|1..4.....|.........|  .........|...4...8.|1.....7..|
                ...4.67..|......78.|.........|  12...6...|.........|.2.4.6...|  .2.45....|.2.45..8.|1.....7..|
                ...4.6...|.........|.........|  .........|.2.4.....|.........|  .........|.2.4.....|.........|

                .2..5....|.........|.........|  .........|.....6..9|.........|  .2..5....|.........|.....6..9|
                .........|.........|.........|  .2......9|...45....|...45....|  .........|.........|.2......9|
                .........|.2....7..|....5.7..|  123..6...|12.......|.23..6...|  .2.45....|.2.456...|.........|
            )"))
        return 1;

    std::cout << "All tests passed!!!" << std::endl;

    return 0;
}