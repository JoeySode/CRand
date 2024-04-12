

#include "cr_seed.h"

#include "cr_generator.h"

#include <time.h>


seed_t crSeedFromBytes(uint8_t* bytes, size_t num_bytes)
{
  seed_t seed = 1;

  for (size_t i = 0; i < num_bytes; i++)
  {
    seed = crGenXorshift(seed + bytes[i]);
    seed = crGenLCG(seed + (i * bytes[i]));
  }

  return seed;
}

seed_t crSeedFromTime()
{
  return (seed_t)time(NULL);
}

seed_t crSeedFromTimeAndBytes(uint8_t* bytes, size_t num_bytes)
{
  return crGenLCG(crSeedFromBytes(bytes, num_bytes) + (seed_t)time(NULL));
}

uint64_t crSeedToRange(seed_t seed, uint64_t min, uint64_t range)
{
  return min + (seed % range);
}

long double crSeedToLongDouble(seed_t seed)
{
  // Clamp for floating point precision
  uint32_t n = (uint32_t)seed;

  return (long double)n / (long double)UINT32_MAX;
}

double crSeedToDouble(seed_t seed)
{
  // Clamp for floating point precision
  uint32_t n = (uint32_t)seed;

  return (double)n / (double)UINT32_MAX;
}

float crSeedToFloat(seed_t seed)
{
  // Clamp for floating point precision
  uint32_t n = (uint32_t)seed;

  return (float)n / (float)UINT32_MAX;
}

bool crSeedToBool(seed_t seed)
{
  return (bool)(seed & 1);
}
