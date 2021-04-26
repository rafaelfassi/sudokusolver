#include "sudoku/Solver.h"
#include <iostream>
#include <sstream>

using namespace sudoku;

bool test(const std::string &puzzle, const std::string &notes, const std::string &expectedNotes)
{
    Grid grid;
    grid.fillValues(puzzle);
    grid.fillNotes(notes);

    Solver::reduceCandidatesBySwordfish(grid);

    Grid gridExpectedNotes;
    gridExpectedNotes.fillNotes(expectedNotes);
    if (!grid.compareNotes(gridExpectedNotes))
    {
        std::cout << std::string(9 * 9, '*') << std::endl;
        std::cout << puzzle << std::endl;
        std::cout << "The notes don't match the expected notes." << std::endl;
        std::cout << std::endl;
        std::cout << "Initial:" << std::endl;
        Grid gridIn;
        gridIn.fillNotes(notes);
        gridIn.dump(Grid::D_NOTES);
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
    // Swordfish row for value 2 at:
    // (1,0) (1,3) .....
    // (2,0) ..... (2,8)
    // ..... (7,3) (7,8)
    if (!test("8.4...1.5.16.85794.9.4.183...25.96....9.3....6518.79.3.437.8.1.168.5437.9.......8",
              R"(
                .........|.23...7..|.........|  .23..6..9|......7.9|.23..6...|  .........|.2...6...|.........|
                .23......|.........|.........|  .23......|.........|.........|  .........|.........|.........|
                .2..5.7..|.........|....5.7..|  .........|.....67..|.........|  .........|.........|.2...6...|

                ..34..7..|..3...78.|.........|  .........|1..4.....|.........|  .........|...4...8.|1.....7..|
                ...4..7..|......78.|.........|  12...6...|.........|.2...6...|  .2.45....|.2.45..8.|1.....7..|
                .........|.........|.........|  .........|.2.4.....|.........|  .........|.2.4.....|.........|

                .2..5....|.........|.........|  .........|.....6..9|.........|  .2..5....|.........|.....6..9|
                .........|.........|.........|  .2......9|.........|.........|  .........|.........|.2......9|
                .........|.2....7..|....5.7..|  123..6...|12.......|.23..6...|  .2.45....|.2.456...|.........|
              )",
              R"(
                .........|.23...7..|.........|  ..3..6..9|......7.9|.23..6...|  .........|.2...6...|.........|
                .23......|.........|.........|  .23......|.........|.........|  .........|.........|.........|
                .2..5.7..|.........|....5.7..|  .........|.....67..|.........|  .........|.........|.2...6...|

                ..34..7..|..3...78.|.........|  .........|1..4.....|.........|  .........|...4...8.|1.....7..|
                ...4..7..|......78.|.........|  1....6...|.........|.2...6...|  .2.45....|.2.45..8.|1.....7..|
                .........|.........|.........|  .........|.2.4.....|.........|  .........|.2.4.....|.........|

                ....5....|.........|.........|  .........|.....6..9|.........|  .2..5....|.........|.....6..9|
                .........|.........|.........|  .2......9|.........|.........|  .........|.........|.2......9|
                .........|.2....7..|....5.7..|  1.3..6...|12.......|.23..6...|  .2.45....|.2.456...|.........|
              )"))
        return 1;

        // Swordfish row for value 2 at:
        // (1,0) (1,4) .....
        // ..... (2,4) (2,7)
        // (8,0) ..... (8,7)
        if (!test("16.543.7..786.14354358.76.172.458.696..912.57...376..4.16.3..4.3...8..16..71645.3",
              R"(
                .........|.........|.2......9|  .........|.........|.........|  .2.....89|.........|.2.....8.|
                .2......9|.........|.........|  .........|.2......9|.........|  .........|.........|.........|
                .........|.........|.........|  .........|.2......9|.........|  .........|.2......9|.........|

                .........|.........|1.3......|  .........|.........|.........|  1.3......|.........|.........|
                .........|...4...8.|..34.....|  .........|.........|.........|  ..3....8.|.........|.........|
                ....5..89|....5..89|1.......9|  .........|.........|.........|  12.....8.|.2.....8.|.........|

                .2..5..89|.........|.........|  .2....7..|.........|....5...9|  .2....789|.........|.2.....8.|
                .........|...45...9|.2.4....9|  .2....7..|.........|....5...9|  .2....7.9|.........|.........|
                .2.....89|.......89|.........|  .........|.........|.........|  .........|.2.....89|.........|
              )",
              R"(
                .........|.........|.2......9|  .........|.........|.........|  .2.....89|.........|.2.....8.|
                .2......9|.........|.........|  .........|.2......9|.........|  .........|.........|.........|
                .........|.........|.........|  .........|.2......9|.........|  .........|.2......9|.........|

                .........|.........|1.3......|  .........|.........|.........|  1.3......|.........|.........|
                .........|...4...8.|..34.....|  .........|.........|.........|  ..3....8.|.........|.........|
                ....5..89|....5..89|1.......9|  .........|.........|.........|  12.....8.|.......8.|.........|

                ....5..89|.........|.........|  .2....7..|.........|....5...9|  .2....789|.........|.2.....8.|
                .........|...45...9|.2.4....9|  .2....7..|.........|....5...9|  .2....7.9|.........|.........|
                .2.....89|.......89|.........|  .........|.........|.........|  .........|.2.....89|.........|
              )"))
        return 1;

    // Swordfish row for value 4 at:
    // (1,1) (1,2) (1,4)
    // (3,1) (3,2) (3,4)
    // ..... (6,2) (6,4)
    if (!test("1.85..2345..3.2178...8..5698..6.5793..59..4813....865298.2.631.......8.....78.9..",
              R"(
                .........|.....67.9|.........|  .........|.....67.9|......7.9|  .........|.........|.........|
                .........|...4.6..9|...4.6..9|  .........|...4.6..9|.........|  .........|.........|.........|
                .2.4..7..|.234..7..|.234..7..|  .........|1..4..7..|1..4..7..|  .........|.........|.........|

                .........|12.4.....|12.4.....|  .........|12.4.....|.........|  .........|.........|.........|
                .2...67..|.2...67..|.........|  .........|.23...7..|..3...7..|  .........|.........|.........|
                .........|1..4..7.9|1..4..7.9|  1..4.....|1..4..7..|.........|  .........|.........|.........|

                .........|.........|...4..7..|  .........|...45....|.........|  .........|.........|....5.7..|
                .2.4.67..|1234567..|1234.67..|  1..4.....|1.345...9|1.34....9|  .........|.2.4.....|....567..|
                .2.4.6...|123456...|1234.6...|  .........|.........|1.34.....|  .........|.2.4.....|....56...|
              )",
              R"(
                .........|.....67.9|.........|  .........|.....67.9|......7.9|  .........|.........|.........|
                .........|...4.6..9|...4.6..9|  .........|...4.6..9|.........|  .........|.........|.........|
                .2.4..7..|.23...7..|.23...7..|  .........|1.....7..|1..4..7..|  .........|.........|.........|

                .........|12.4.....|12.4.....|  .........|12.4.....|.........|  .........|.........|.........|
                .2...67..|.2...67..|.........|  .........|.23...7..|..3...7..|  .........|.........|.........|
                .........|1.....7.9|1.....7.9|  1..4.....|1.....7..|.........|  .........|.........|.........|

                .........|.........|...4..7..|  .........|...45....|.........|  .........|.........|....5.7..|
                .2.4.67..|123.567..|123..67..|  1..4.....|1.3.5...9|1.34....9|  .........|.2.4.....|....567..|
                .2.4.6...|123.56...|123..6...|  .........|.........|1.34.....|  .........|.2.4.....|....56...|
              )"))
        return 1;

    // TODO
    // Swordfish column for value 7 at:
    // (0,1) (0,4) .....
    // (5,1) ..... (5,7)
    // ..... (8,4) (8,7)
    // if (!test("..9..6.4.....1.76..65.42.98396.85.2..52.6.98....29...664..5.23...7.2.6...2.6..8..",
    //           R"(
    //             12....78.|1.3...78.|.........|  ....5..8.|..3...7..|.........|  1.3.5....|.........|123.5....|
    //             .2.4...8.|..3....8.|..34...8.|  ....5..89|.........|.......89|  .........|.........|.23.5....|
    //             1.....7..|.........|.........|  ..3...7..|.........|.........|  1.3......|.........|.........|

    //             .........|.........|.........|  1..4..7..|.........|.........|  1..4.....|.........|1.....7..|
    //             1..4..7..|.........|.........|  1.34..7..|.........|1.34..7..|  .........|.........|1.3...7..|
    //             1..4..78.|1.....78.|1..4...8.|  .........|.........|1.34..7..|  1.345....|1...5.7..|.........|

    //             .........|.........|1......8.|  1.....789|.........|1.....789|  .........|.........|1.....7.9|
    //             ....5...9|1.3....8.|.........|  1.34...89|.........|1.34...89|  .........|1...5....|1..45...9|
    //             ....5...9|.........|1.3......|  .........|..3...7..|1.34..7.9|  .........|1...5.7..|1..45.7.9|
    //           )",
    //           R"(
    //             12.....8.|1.3...78.|.........|  ....5..8.|..3...7..|.........|  1.3.5....|.........|123.5....|
    //             .2.4...8.|..3....8.|..34...8.|  ....5..89|.........|.......89|  .........|.........|.23.5....|
    //             1.....7..|.........|.........|  ..3...7..|.........|.........|  1.3......|.........|.........|

    //             .........|.........|.........|  1..4..7..|.........|.........|  1..4.....|.........|1.....7..|
    //             1..4..7..|.........|.........|  1.34..7..|.........|1.34..7..|  .........|.........|1.3...7..|
    //             1..4...8.|1.....78.|1..4...8.|  .........|.........|1.34.....|  1.345....|1...5.7..|.........|

    //             .........|.........|1......8.|  1.....789|.........|1.....789|  .........|.........|1.....7.9|
    //             ....5...9|1.3....8.|.........|  1.34...89|.........|1.34...89|  .........|1...5....|1..45...9|
    //             ....5...9|.........|1.3......|  .........|..3...7..|1.34....9|  .........|1...5.7..|1..45...9|
    //           )"))
    //     return 1;

    std::cout << "All tests passed!!!" << std::endl;

    return 0;
}