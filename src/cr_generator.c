

#include "cr_generator.h"


seed_t crGenXorshift(seed_t seed)
{
  seed ^= seed << 13;
  seed ^= seed >> 7;
  seed ^= seed << 17;

  return seed;
}

seed_t crGenLCG(seed_t seed)
{
  // m is 2^64
  const uint64_t a = 793131594457ULL; // Must be prime and (a - 1) must be a multiple of 4
  const uint64_t c = 93465923;        // Must be coprime with m

  return (seed * a) + c;
}
