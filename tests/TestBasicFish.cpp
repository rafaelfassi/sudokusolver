#include "Test.h"

bool test(solver::BasicFishType fishType, const std::string &puzzle, const std::string &board,
          solver::Technique expectedTechnique)
{
    Grid grid;
    grid.fillBoard(board);

    solver::Logs logs;
    bool changed = solver::techniques::basicFish(grid, fishType, &logs);

    return checkAll(puzzle, grid, board, changed, expectedTechnique, logs);
}

int main(int, char **)
{
    // Row
    if (!test(solver::BasicFishType::Swordfish,
              "8.4...1.5.16.85794.9.4.183...25.96....9.3....6518.79.3.437.8.1.168.5437.9.......8",
              R"(
                .-----------------.------------------.------------------.
                | 8       237  4  | (-2)369  79  236 | 1    26    5     |
                | (*2)3   1    6  | (*2)3    8   5   | 7    9     4     |
                | (*2)57  9    57 | 4        67  1   | 8    3     (*2)6 |
                :-----------------+------------------+------------------:
                | 347     378  2  | 5        14  9   | 6    48    17    |
                | 47      78   9  | 1(-2)6   3   26  | 245  2458  17    |
                | 6       5    1  | 8        24  7   | 9    24    3     |
                :-----------------+------------------+------------------:
                | (-2)5   4    3  | 7        69  8   | 25   1     69    |
                | 1       6    8  | (*2)9    5   4   | 3    7     (*2)9 |
                | 9       27   57 | 1(-2)36  12  236 | 245  2456  8     |
                '-----------------'------------------'------------------'
              )",
              solver::Technique::Swordfish))
        return failed();

    // Row
    if (!test(solver::BasicFishType::Swordfish,
              "16.543.7..786.14354358.76.172.458.696..912.57...376..4.16.3..4.3...8..16..71645.3",
              R"(
                .-------------------.---------------.------------------.
                | 1        6    29  | 5   4      3  | 289   7       28 |
                | (*2)9    7    8   | 6   (*2)9  1  | 4     3       5  |
                | 4        3    5   | 8   (*2)9  7  | 6     (*2)9   1  |
                :-------------------+---------------+------------------:
                | 7        2    13  | 4   5      8  | 13    6       9  |
                | 6        48   34  | 9   1      2  | 38    5       7  |
                | 589      589  19  | 3   7      6  | 128   (-2)8   4  |
                :-------------------+---------------+------------------:
                | (-2)589  1    6   | 27  3      59 | 2789  4       28 |
                | 3        459  249 | 27  8      59 | 279   1       6  |
                | (*2)89   89   7   | 1   6      4  | 5     (*2)89  3  |
                '-------------------'---------------'------------------'
              )",
              solver::Technique::Swordfish))
        return failed();

    // Row
    if (!test(solver::BasicFishType::Swordfish,
              "985.1..7.1.49.6.58.6..5819.793165842428.9..1.6512849378465.1.295..6.9481.1984..6.",
              R"(
                .---------------.------------------.----------------.
                | 9   8      5  | 34   1       23  | 2(-3)6  7  346 |
                | 1   (*3)7  4  | 9    2(*3)7  6   | 2(*3)   5  8   |
                | 23  6      27 | 347  5       8   | 1       9  34  |
                :---------------+------------------+----------------:
                | 7   9      3  | 1    6       5   | 8       4  2   |
                | 4   2      8  | 37   9       37  | 56      1  56  |
                | 6   5      1  | 2    8       4   | 9       3  7   |
                :---------------+------------------+----------------:
                | 8   4      6  | 5    (*3)7   1   | (*3)7   2  9   |
                | 5   (*3)7  27 | 6    2(*3)   9   | 4       8  1   |
                | 23  1      9  | 8    4       237 | (-3)57  6  35  |
                '---------------'------------------'----------------'
              )",
              solver::Technique::Swordfish))
        return failed();

    // Row
    if (!test(solver::BasicFishType::Swordfish,
              ".4.3.5.2...7.4.3.1...1.8..4.9...6.48..4...7..5..4...9.4..5.....8.3.1.4...6.8.4.3.",
              R"(
                .-------------------------.-------------------.-----------------------.
                | (*1)69   4      (*1)689 | 3     679    5    | 689       2     679   |
                | 269      58     7       | 269   4      29   | 3         58    1     |
                | 2369     235    2569    | 1     2679   8    | 569       567   4     |
                :-------------------------+-------------------+-----------------------:
                | (*1)237  9      (*1)2   | 27    235    6    | (*1)25    4     8     |
                | (-1)236  1238   4       | 29    23589  1239 | 7         156   2356  |
                | 5        12378  (-1)268 | 4     238    1237 | (-1)26    9     236   |
                :-------------------------+-------------------+-----------------------:
                | 4        127    (-1)29  | 5     2369   2379 | (-1)2689  1678  2679  |
                | 8        257    3       | 2679  1      279  | 4         567   25679 |
                | (*1)279  6      (*1)259 | 8     29     4    | (*1)259   3     2579  |
                '-------------------------'-------------------'-----------------------'
              )",
              solver::Technique::Swordfish))
        return failed();

    // Row
    if (!test(solver::BasicFishType::Swordfish,
              "1......3.....17..25....49..8..9.62..9..47.3.6..71.2.95..18..7.47..6....9.5.7....3",
              R"(
                .----------------------.--------------.-----------------.
                | 1       27      24   | 25  69   89  | 456  3       78 |
                | 34(*6)  89      89   | 35  1    7   | 45   4(*6)   2  |
                | 5       3(-6)7  236  | 23  68   4   | 9    17      18 |
                :----------------------+--------------+-----------------:
                | 8       14      35   | 9   35   6   | 2    47      17 |
                | 9       12      25   | 4   7    58  | 3    18      6  |
                | 34(*6)  34(*6)  7    | 1   38   2   | 48   9       5  |
                :----------------------+--------------+-----------------:
                | 23(*6)  3(*6)9  1    | 8   259  359 | 7    25(*6)  4  |
                | 7       348     348  | 6   245  135 | 18   258     9  |
                | 24(-6)  5       4689 | 7   249  19  | 168  2(-6)8  3  |
                '----------------------'--------------'-----------------'
              )",
              solver::Technique::Swordfish))
        return failed();

    // Column
    if (!test(solver::BasicFishType::Swordfish,
              "..9..6.4.....1.76..65.42.98396.85.2..52.6.98....29...664..5.23...7.2.6...2.6..8..",
              R"(
                .-----------------------.------------------------.------------------------.
                | 12(-7)8  13(*7)8  9   | 58     3(*7)  6        | 135   4       1235     |
                | 248      38       348 | 589    1      89       | 7     6       235      |
                | 17       6        5   | 37     4      2        | 13    9       8        |
                :-----------------------+------------------------+------------------------:
                | 3        9        6   | 147    8      5        | 14    2       17       |
                | 147      5        2   | 1347   6      1347     | 9     8       137      |
                | 14(-7)8  1(*7)8   148 | 2      9      134(-7)  | 1345  15(*7)  6        |
                :-----------------------+------------------------+------------------------:
                | 6        4        18  | 1789   5      1789     | 2     3       179      |
                | 59       138      7   | 13489  2      13489    | 6     15      1459     |
                | 59       2        13  | 6      3(*7)  134(-7)9 | 8     15(*7)  145(-7)9 |
                '-----------------------'------------------------'------------------------'
              )",
              solver::Technique::Swordfish))
        return failed();

    // Column
    if (!test(solver::BasicFishType::Swordfish,
              "76..984353.4675.8959843..76.56.493272...5.9644.9.6.8519..52461.64.3.759...59.674.",
              R"(
                .---------------.-------------------.--------------.
                | 7   6      12 | 12      9   8     | 4      3  5  |
                | 3   (*1)2  4  | 6       7   5     | (*1)2  8  9  |
                | 5   9      8  | 4       3   (*1)2 | (*1)2  7  6  |
                :---------------+-------------------+--------------:
                | 18  5      6  | 18      4   9     | 3      2  7  |
                | 2   (*1)8  37 | (-1)78  5   (*1)3 | 9      6  4  |
                | 4   37     9  | 27      6   23    | 8      5  1  |
                :---------------+-------------------+--------------:
                | 9   378    37 | 5       2   4     | 6      1  38 |
                | 6   4      12 | 3       18  7     | 5      9  28 |
                | 18  23     5  | 9       18  6     | 7      4  23 |
                '---------------'-------------------'--------------'
              )",
              solver::Technique::Swordfish))
        return failed();

    // Column
    if (!test(solver::BasicFishType::Swordfish,
              "816.3.4.973....8..59.8..3.72476.8.35.53.2.68468.4537..328.75.46.6.28457347536.2.8",
              R"(
                .-----------.-----------------------.-----------------.
                | 8   1  6  | 57      3      27     | 4      25    9  |
                | 7   3  24 | 15(*9)  4(*9)  26(-9) | 8      1256  12 |
                | 5   9  24 | 8       14     126    | 3      126   7  |
                :-----------+-----------------------+-----------------:
                | 2   4  7  | 6       1(*9)  8      | 1(*9)  3     5  |
                | 19  5  3  | 17      2      179    | 6      8     4  |
                | 6   8  19 | 4       5      3      | 7      129   12 |
                :-----------+-----------------------+-----------------:
                | 3   2  8  | 1(*9)   7      5      | 1(*9)  4     6  |
                | 19  6  19 | 2       8      4      | 5      7     3  |
                | 4   7  5  | 3       6      19     | 2      19    8  |
                '-----------'-----------------------'-----------------'
              )",
              solver::Technique::Swordfish))
        return failed();

    // Column
    if (!test(solver::BasicFishType::Swordfish,
              ".572...312.15738.....41957251.6.2..7..2.4531....7.1625..532.1..1.6.5.2.332.1..75.",
              R"(
                .-----------------------.---------------------.----------------------.
                | 49     5        7     | 2   68      68      | 49  3        1       |
                | 2      49       1     | 5   7       3       | 8   469      469     |
                | 6(*8)  36(-8)   3(*8) | 4   1       9       | 5   7        2       |
                :-----------------------+---------------------+----------------------:
                | 5      1        3(*8) | 6   3(-8)9  2       | 49  4(*8)    7       |
                | 67     67       2     | 89  4       5       | 3   1        89      |
                | 49     38       49    | 7   38      1       | 6   2        5       |
                :-----------------------+---------------------+----------------------:
                | 7(*8)  47(-8)9  5     | 3   2       467(-8) | 1   46(*8)9  46(-8)9 |
                | 1      4789     6     | 89  5       478     | 2   49       3       |
                | 3      2        49    | 1   689     468     | 7   5        468     |
                '-----------------------'---------------------'----------------------'
              )",
              solver::Technique::Swordfish))
        return failed();

    // Row
    if (!test(solver::BasicFishType::Jellyfish,
              "9...5.648...6.2..77..94832.5....98.3.792...6.3.15....2.98.7..36.57396.8.63482...9",
              R"(
                .------------.--------------------.-------------------.
                | 9   12  23 | 17  5       (-1)37 | 6      4       8  |
                | 48  48  35 | 6   (*1)3   2      | (*1)9  (*1)59  7  |
                | 7   16  56 | 9   4       8      | 3      2       15 |
                :------------+--------------------+-------------------:
                | 5   24  26 | 47  (*1)6   9      | 8      (*1)7   3  |
                | 48  7   9  | 2   (*1)38  (*1)3  | (*1)5  6       45 |
                | 3   68  1  | 5   68      47     | 479    79      2  |
                :------------+--------------------+-------------------:
                | 12  9   8  | 14  7       (-1)45 | 25     3       6  |
                | 12  5   7  | 3   9       6      | 24     8       14 |
                | 6   3   4  | 8   2       (*1)5  | (*1)7  (*1)57  9  |
                '------------'--------------------'-------------------'
              )",
              solver::Technique::Jellyfish))
        return failed();

    // Row
    if (!test(solver::BasicFishType::Jellyfish,
              ".513..826376.8....28...6.3.62..34.9..136..2.4.4.52..63.9.8.36.2.3..6.945.62...3..",
              R"(
                .-----------------.------------------------.------------------.
                | 49       5  1   | 3    4(*7)9    (*7)9   | 8    2       6   |
                | 3        7  6   | 249  8         125     | 45   15      19  |
                | 2        8  49  | 149  15        6       | 457  3       179 |
                :-----------------+------------------------+------------------:
                | 6        2  58  | 17   3         4       | 157  9       78  |
                | 5(*7)89  1  3   | 6    (*7)9     (*7)89  | 2    58      4   |
                | (-7)89   4  789 | 5    2         1(-7)89 | 17   6       3   |
                :-----------------+------------------------+------------------:
                | 145      9  45  | 8    15(*7)    3       | 6    1(*7)   2   |
                | 1(-7)8   3  78  | 127  6         12      | 9    4       5   |
                | 15(*7)   6  2   | 49   145(*7)9  15(*7)9 | 3    1(*7)8  18  |
                '-----------------'------------------------'------------------'
              )",
              solver::Technique::Jellyfish))
        return failed();

    // Row
    if (!test(solver::BasicFishType::Jellyfish,
              "5.......3...935.6.4.3..795.3...5162.245...7.168172...5..65..2.9934.625...52.....6",
              R"(
                .-----------------.--------------------------.------------------------.
                | 5    12679  789 | 1246(-8)  14(-8)    468  | 18    17(-8)   3       |
                | 17   127    78  | 9         3         5    | 148   6        247(-8) |
                | 4    126    3   | 126(*8)   1(*8)     7    | 9     5        2(*8)   |
                :-----------------+--------------------------+------------------------:
                | 3    79     79  | 4(*8)     5         1    | 6     2        4(*8)   |
                | 2    4      5   | 36        (*8)9     36   | 7     (*8)9    1       |
                | 6    8      1   | 7         2         49   | 34    349      5       |
                :-----------------+--------------------------+------------------------:
                | 178  17     6   | 5         147(-8)   348  | 2     134(-8)  9       |
                | 9    3      4   | 1(*8)     6         2    | 5     17(*8)   7(*8)   |
                | 178  5      2   | 134(-8)   147(-8)9  3489 | 1348  134(-8)  6       |
                '-----------------'--------------------------'------------------------'
              )",
              solver::Technique::Jellyfish))
        return failed();

    // Row
    if (!test(solver::BasicFishType::Jellyfish,
              "7.69..84..8...4..73...78..9.3...9.1.2..783.56.5.4.....56.2.7..44....6.7..738456..",
              R"(
                .---------------------.-----------------------.-----------------.
                | 7   (*1)2   6       | 9     35        (*1)2 | 8     4     35  |
                | 19  8       (-1)259 | 1356  (-1)2356  4     | 1235  236   7   |
                | 3   (-1)24  (-1)245 | 156   7         8     | 12    26    9   |
                :---------------------+-----------------------+-----------------:
                | 68  3       47      | 56    256       9     | 47    1     28  |
                | 2   (*1)49  (*1)49  | 7     8         3     | 49    5     6   |
                | 68  5       79      | 4     (*1)26    (*1)2 | 2379  2389  38  |
                :---------------------+-----------------------+-----------------:
                | 5   6       (*1)89  | 2     (*1)39    7     | 39    389   4   |
                | 4   (-1)29  289     | 13    (-1)39    6     | 359   7     158 |
                | 19  7       3       | 8     4         5     | 6     29    12  |
                '---------------------'-----------------------'-----------------'
              )",
              solver::Technique::Jellyfish))
        return failed();

    // Column
    if (!test(solver::BasicFishType::Jellyfish,
              "..36....1...3...6.69..15743.4.562.3.2.9.3.4.636..94.2.526.7.39.9...5367.7349.651.",
              R"(
                .-----------------------.-----------------------.----------------------.
                | 4(-8)  57(-8)   3     | 6       24(*8)  79    | 2(-8)9  5(*8)  1     |
                | 148    178      12578 | 3       24      79    | 289     6      59    |
                | 6      9        28    | 28      1       5     | 7       4      3     |
                :-----------------------+-----------------------+----------------------:
                | 18     4        178   | 5       6       2     | 189     3      79    |
                | 2      157(-8)  9     | 17(-8)  3       1(*8) | 4       5(*8)  6     |
                | 3      6        1578  | 178     9       4     | 18      2      57    |
                :-----------------------+-----------------------+----------------------:
                | 5      2        6     | 14(-8)  7       1(*8) | 3       9      4(*8) |
                | 9      18       18    | 24      5       3     | 6       7      24    |
                | 7      3        4     | 9       2(*8)   6     | 5       1      2(*8) |
                '-----------------------'-----------------------'----------------------'
              )",
              solver::Technique::Jellyfish))
        return failed();

    // Column
    if (!test(solver::BasicFishType::Jellyfish,
              ".9.42531.3256.1..914.9.3562914.68..3..23198....3.4.19.231.946.545..36..1...15..3.",
              R"(
                .-----------------------.-------------------.----------------------.
                | 6(*7)8  9       6(-7) | 4       2   5     | 3        1    (*7)8  |
                | 3       2       5     | 6       78  1     | 47       478  9      |
                | 1       4       78    | 9       78  3     | 5        6    2      |
                :-----------------------+-------------------+----------------------:
                | 9       1       4     | 57      6   8     | 27       257  3      |
                | 56(*7)  6(*7)   2     | 3       1   9     | 8        45   46(*7) |
                | 568     6(*7)8  3     | 25(-7)  4   2(*7) | 1        9    6(*7)  |
                :-----------------------+-------------------+----------------------:
                | 2       3       1     | 78      9   4     | 6        78   5      |
                | 4       5       789   | 278     3   6     | 79       278  1      |
                | 6(*7)8  6(*7)8  69    | 1       5   2(*7) | 24(-7)9  3    4(*7)8 |
                '-----------------------'-------------------'----------------------'
              )",
              solver::Technique::Jellyfish))
        return failed();

    return passed();
}