

#include "cr_twister.h"

#include <stddef.h>


#define CR_N 312
#define CR_M 156

#define CR_A 0xB5026F5AA96619E9ULL
#define CR_B 0x71D67FFFEDA60000ULL
#define CR_C 0xFFF7EEE000000000ULL
#define CR_D 0xFFFFFFFFFFFFFFFFULL
#define CR_F 6364136223846793005ULL

#define CR_U 29
#define CR_S 17
#define CR_T 37
#define CR_L 43


static void crTwisterTwist(twister_t* p_twister)
{
  // Define masks
  uint64_t upper_mask = 0x8000000000000000ULL;
  uint64_t lower_mask = 0x7FFFFFFFFFFFFFFFULL;

  for (size_t i = 0; i < CR_N; i++)
  {
    // Preform the twist algorithm
    uint64_t x = (p_twister->state[i] & upper_mask) + (p_twister->state[(i + 1) % CR_N] & lower_mask);

    uint64_t xa = x >> 1;

    if (x & 1)
      xa ^= CR_A;

    p_twister->state[i] = p_twister->state[(i + CR_M) % CR_N] ^ xa;
  }

  // Go back to the start
  p_twister->index = 0;
}


void crTwisterInit(twister_t* p_twister, seed_t seed)
{
  // Seed the twister
  p_twister->state[0] = seed;

  for (size_t i = 1; i < CR_N; i++)
  {
    const uint64_t prev = p_twister->state[i - 1];

    p_twister->state[i] = CR_F * (prev ^ (prev >> 62)) + i;
  }

  p_twister->index = 0;
}

seed_t crTwisterGen(twister_t* p_twister)
{
  // Twist if needed
  if (p_twister->index >= CR_N)
    crTwisterTwist(p_twister);

  // Proceed with the current value
  seed_t y = p_twister->state[p_twister->index];

  p_twister->index += 1;

  // Temper the current value bit bitwise operations and return it
  y ^= y >> CR_U;
  y ^= ((y << CR_S) & CR_B);
  y ^= ((y << CR_T) & CR_C);
  y ^= y >> CR_L;

  return y;
}
