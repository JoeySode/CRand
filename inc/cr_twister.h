

#ifndef CR_TWISTER_H_

#define CR_TWISTER_H_


#include <stdint.h>

#include "cr_seed.h"


// A morsenne twister (MT9937-64)
typedef struct
{
  seed_t state[312];  // The twister's state (should only be modified by CRand functions)
  size_t index;       // The twister's state index (should only be modified by CRand functions)
}
twister_t;


// Initializes the twister with the given seed
void crTwisterInit(twister_t* p_twister, seed_t seed);

// Generates a random number from the twister, advancing its state
seed_t crTwisterGen(twister_t* p_twister);


#endif // CR_TWISTER_H_
