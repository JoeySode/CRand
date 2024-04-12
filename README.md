# CRand

CRand is a light pseudo-RNG library

## Installation

Go into the repository and call 'make'. This will compile the binaries into a build directory and create 'libcrand.a'. Run 'make clean' to remove the build directory.

## Example

```c
twister_t t;
crTwisterInit(&t, crSeedFromTime());

for (int i = 0; i < 10; i++)
  printf("%llu\n", crTwisterGen(&t));
```

## Contributing

Pull requests are welcome and appreciated.

## License

[MIT](https://choosealicense.com/licenses/mit/)