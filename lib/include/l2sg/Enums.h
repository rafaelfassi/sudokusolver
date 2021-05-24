#ifndef L2SG_ENUMS_H
#define L2SG_ENUMS_H

#include <string>

namespace l2sg
{

namespace solver
{

enum class Technique
{
    None,
    NakedSingles,
    NakedPair,
    NakedTriple,
    NakedQuadruple,
    HiddenSingles,
    HiddenPair,
    HiddenTriple,
    HiddenQuadruple,
    LockedCandidatesType1,
    LockedCandidatesType2,
    XWings,
    Swordfish,
    Jellyfish,
    XYWing,
    WWing,
    Skyscraper,
    TwoStringKite,
    SimpleGuess,
    BruteForce
};

enum class LockedCandType
{
    Type1Pointing,
    Type2Claiming
};

enum class HiddenMultiType
{
    Pair = 2,
    Triple = 3,
    Quadruple = 4
};

enum class NakedMultiType
{
    Pair = 2,
    Triple = 3,
    Quadruple = 4
};

enum class BasicFishType
{
    Swordfish = 3,
    Jellyfish = 4
};

std::string technique2Str(solver::Technique technique);

} // namespace solver

enum Level
{
    LEV_0_LOGIC,
    LEV_1_LOGIC,
    LEV_2_LOGIC,
    LEV_3_GUESS,
    LEV_UNKNOWN
};

enum class CellAction
{
    AppliedValue,
    RemovedNote,
    InPatternN1,
    InPatternN2
};

std::string cellAction2Str(CellAction action);

} // namespace l2sg

#endif // L2SG_ENUMS_H
