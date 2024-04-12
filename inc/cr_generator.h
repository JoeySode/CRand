

#ifndef CR_GENERATOR_H_

#define CR_GENERATOR_H_


#include "cr_seed.h"


// A function that takes a seed state and returns the next one in its PRNG sequence
typedef seed_t(*generator_t)(seed_t seed);


/*
  Xorshift algorithm
  [https://en.wikipedia.org/wiki/Xorshift]

  Pros:
    Fast
    Unpredictable

  Cons:
    0 is a dead value
*/
seed_t crGenXorshift(seed_t seed);

/*
  Linear Congruential Generator (LCG)
  [https://en.wikipedia.org/wiki/Linear_congruential_generator]

  Pros:
    Very fast

  Cons:
    Somewhat-predictable
*/
seed_t crGenLCG(seed_t seed);


#endif // CR_GENERATOR_H_
