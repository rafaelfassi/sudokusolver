#include "Test.h"

bool test(const std::string &puzzle, const std::string &board, const std::string &expectedBoard)
{
    Grid grid;
    grid.fillFromSolutionGrid(board);

    solver::techniques::nakedSingles(grid);

    return checkAll(puzzle, grid, board, expectedBoard);
}

int main(int, char **)
{
    // Full House in row for value 4 at: (1,1)
    if (!test("1..6...928.2951673.9.3.2.41....26......198......53....96...3.8.21..659377....9..6",
              R"(
                .------------------.--------------.---------------.
                | 1     3457  3457 | 6    478  47 | 58    9    2  |
                | 8     4     2    | 9    5    1  | 6     7    3  |
                | 56    9     567  | 3    78   2  | 58    4    1  |
                :------------------+--------------+---------------:
                | 345   578   19   | 47   2    6  | 347   15   89 |
                | 3456  257   567  | 1    9    8  | 2347  256  45 |
                | 46    278   19   | 5    3    47 | 247   126  89 |
                :------------------+--------------+---------------:
                | 9     6     45   | 27   17   3  | 12    8    45 |
                | 2     1     48   | 48   6    5  | 9     3    7  |
                | 7     345   3458 | 248  14   9  | 124   25   6  |
                '------------------'--------------'---------------'
              )",
              R"(
                .-----------------.--------------.---------------.
                | 1     357  357  | 6    478  47 | 58    9    2  |
                | 8     4    2    | 9    5    1  | 6     7    3  |
                | 56    9    567  | 3    78   2  | 58    4    1  |
                :-----------------+--------------+---------------:
                | 345   578  19   | 47   2    6  | 347   15   89 |
                | 3456  257  567  | 1    9    8  | 2347  256  45 |
                | 46    278  19   | 5    3    47 | 247   126  89 |
                :-----------------+--------------+---------------:
                | 9     6    45   | 27   17   3  | 12    8    45 |
                | 2     1    48   | 48   6    5  | 9     3    7  |
                | 7     35   3458 | 248  14   9  | 124   25   6  |
                '-----------------'--------------'---------------'
              )"))
        return failed();

    // Full House in column for value 7 at: (5,8)
    if (!test(".429..7.559.76.3423..524.19.5.1.92.3823657194..9..2.5.28..9.576.35..69219.62.5438",
              R"(
                .-------------.--------------.-----------.
                | 16   4   2  | 9    13   38 | 7   68  5 |
                | 5    9   18 | 7    6    18 | 3   4   2 |
                | 3    67  78 | 5    2    4  | 68  1   9 |
                :-------------+--------------+-----------:
                | 467  5   47 | 1    48   9  | 2   68  3 |
                | 8    2   3  | 6    5    7  | 1   9   4 |
                | 147  16  9  | 348  348  2  | 68  5   7 |
                :-------------+--------------+-----------:
                | 2    8   14 | 34   9    13 | 5   7   6 |
                | 47   3   5  | 48   478  6  | 9   2   1 |
                | 9    17  6  | 2    17   5  | 4   3   8 |
                '-------------'--------------'-----------'
              )",
              R"(
                .-------------.--------------.-----------.
                | 16   4   2  | 9    13   38 | 7   68  5 |
                | 5    9   18 | 7    6    18 | 3   4   2 |
                | 3    67  78 | 5    2    4  | 68  1   9 |
                :-------------+--------------+-----------:
                | 467  5   47 | 1    48   9  | 2   68  3 |
                | 8    2   3  | 6    5    7  | 1   9   4 |
                | 14   16  9  | 348  348  2  | 68  5   7 |
                :-------------+--------------+-----------:
                | 2    8   14 | 34   9    13 | 5   7   6 |
                | 47   3   5  | 48   478  6  | 9   2   1 |
                | 9    17  6  | 2    17   5  | 4   3   8 |
                '-------------'--------------'-----------'
              )"))
        return failed();

    // Full House in block for value 1 at: (2,0)
    if (!test("2859.74.6673.4.....94..6...93876...4.2..9.36.4.....79.3.26.....8...5.12...98..643",
              R"(
                .--------------.----------------.---------------.
                | 2    8    5  | 9    13  7     | 4    13  6    |
                | 6    7    3  | 125  4   158   | 29   58  129  |
                | 1    9    4  | 125  38  6     | 58   37  127  |
                :--------------+----------------+---------------:
                | 9    3    8  | 7    6   125   | 25   15  4    |
                | 157  2    17 | 145  9   1458  | 3    6   158  |
                | 4    156  16 | 135  28  12358 | 7    9   1258 |
                :--------------+----------------+---------------:
                | 3    14   2  | 6    17  49    | 589  78  59   |
                | 8    46   67 | 34   5   349   | 1    2   79   |
                | 157  15   9  | 8    27  12    | 6    4   3    |
                '--------------'----------------'---------------'
              )",
              R"(
                .-------------.----------------.---------------.
                | 2   8    5  | 9    13  7     | 4    13  6    |
                | 6   7    3  | 125  4   158   | 29   58  129  |
                | 1   9    4  | 25   38  6     | 58   37  27   |
                :-------------+----------------+---------------:
                | 9   3    8  | 7    6   125   | 25   15  4    |
                | 57  2    17 | 145  9   1458  | 3    6   158  |
                | 4   156  16 | 135  28  12358 | 7    9   1258 |
                :-------------+----------------+---------------:
                | 3   14   2  | 6    17  49    | 589  78  59   |
                | 8   46   67 | 34   5   349   | 1    2   79   |
                | 57  15   9  | 8    27  12    | 6    4   3    |
                '-------------'----------------'---------------'
              )"))
        return failed();

    // Naked Single for value 4 at: (8,0)
    if (!test("98.7..6....7.5..495....9...3..9....879.18.2....8..5.9781..4.9....95...84....9....",
              R"(
                .-------------------.---------------------.---------------------.
                | 9    8       1234 | 7      13     1234  | 6     1235    1235  |
                | 126  236     7    | 2368   5      12368 | 138   4       9     |
                | 5    2346    1236 | 23468  136    9     | 1378  1237    123   |
                :-------------------+---------------------+---------------------:
                | 3    45      126  | 9      27     267   | 45    16      8     |
                | 7    9       456  | 1      8      346   | 2     356     356   |
                | 126  246     8    | 346    236    5     | 134   9       7     |
                :-------------------+---------------------+---------------------:
                | 8    1       2356 | 236    4      237   | 9     23567   2356  |
                | 26   2367    9    | 5      12367  123   | 37    8       4     |
                | 4    234567  236  | 2368   9      23678 | 157   123567  12356 |
                '-------------------'---------------------'---------------------'
              )",
              R"(
                .------------------.---------------------.---------------------.
                | 9    8      1234 | 7      13     1234  | 6     1235    1235  |
                | 126  236    7    | 2368   5      12368 | 138   4       9     |
                | 5    2346   1236 | 23468  136    9     | 1378  1237    123   |
                :------------------+---------------------+---------------------:
                | 3    45     126  | 9      27     267   | 45    16      8     |
                | 7    9      456  | 1      8      346   | 2     356     356   |
                | 126  246    8    | 346    236    5     | 134   9       7     |
                :------------------+---------------------+---------------------:
                | 8    1      2356 | 236    4      237   | 9     23567   2356  |
                | 26   2367   9    | 5      12367  123   | 37    8       4     |
                | 4    23567  236  | 2368   9      23678 | 157   123567  12356 |
                '------------------'---------------------'---------------------'
              )"))
        return failed();

    // Naked Single for value 4 at: (3,6)
    if (!test("89.54..1..2493..857...86.9..1..78.2..47.1.869...69..71.6.82.947....5.236....69158",
              R"(
                .----------------.--------------.-------------.
                | 8    9    36   | 5    4  27   | 67   1  23  |
                | 16   2    4    | 9    3  17   | 67   8  5   |
                | 7    35   135  | 12   8  6    | 34   9  234 |
                :----------------+--------------+-------------:
                | 569  1    569  | 34   7  8    | 5    2  34  |
                | 235  4    7    | 23   1  235  | 8    6  9   |
                | 235  358  2358 | 6    9  2345 | 345  7  1   |
                :----------------+--------------+-------------:
                | 135  6    135  | 8    2  13   | 9    4  7   |
                | 49   78   189  | 147  5  14   | 2    3  6   |
                | 234  37   23   | 347  6  9    | 1    5  8   |
                '----------------'--------------'-------------'
              )",
              R"(
                .----------------.--------------.------------.
                | 8    9    36   | 5    4  27   | 67  1  23  |
                | 16   2    4    | 9    3  17   | 67  8  5   |
                | 7    35   135  | 12   8  6    | 34  9  234 |
                :----------------+--------------+------------:
                | 69   1    69   | 34   7  8    | 5   2  34  |
                | 235  4    7    | 23   1  235  | 8   6  9   |
                | 235  358  2358 | 6    9  2345 | 34  7  1   |
                :----------------+--------------+------------:
                | 135  6    135  | 8    2  13   | 9   4  7   |
                | 49   78   189  | 147  5  14   | 2   3  6   |
                | 234  37   23   | 347  6  9    | 1   5  8   |
                '----------------'--------------'------------'
              )"))
        return failed();

    return passed();
}