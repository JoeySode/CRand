

#ifndef CR_SEED_H_

#define CR_SEED_H_


#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// A type representing a PRNG seed state
typedef uint64_t seed_t;


// Returns a seed generated from the given byte array
seed_t crSeedFromBytes(uint8_t* bytes, size_t num_bytes);

// Returns a seed generated from the time since epoch
seed_t crSeedFromTime();

// Returns a seed generated from the time since epoch and the given byte array
seed_t crSeedFromTimeAndBytes(uint8_t* bytes, size_t num_bytes);

// Returns a number within the given range generated from the seed (inclusive of min, exclusive of min+range)
uint64_t crSeedToRange(seed_t seed, uint64_t min, uint64_t range);

// Returns a double generated from the seed (range 0 to 1 inclusive)
long double crSeedToLongDouble(seed_t seed);

// Returns a double generated from the seed (range 0 to 1 inclusive)
double crSeedToDouble(seed_t seed);

// Returns a float generated from the seed (range 0 to 1 inclusive)
float crSeedToFloat(seed_t seed);

// Returns true 50% of the time
bool crSeedToBool(seed_t seed);


#endif // CR_SEED_H_
