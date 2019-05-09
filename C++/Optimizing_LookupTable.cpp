/*

  Harjoitus 1

  Optimoi sini-funktion käsittely. Älä muuta kääntäjäoptioita.
  Vertaa alkuperäistä ja optimoitua versiota:

  - kuinka paljon enemmän muistia optimoitu versio kuluttaa?
  - kuinka paljon nopeammin optimoitu versio toimii?

  Käännös: gcc sin.c -lm -o sin

*/

#include <stdio.h>
#include <time.h>
#include <math.h>

#define DEG_TO_RAD(A) (A / 57.296)
constexpr auto ITERATIONS = 1000000;


int main()
{
	double _lookupTable[360];
	for (int i = 0; i < 360; i++) {
		_lookupTable[i] = sin(DEG_TO_RAD(i));
	}
	clock_t t1, t2;
	unsigned i, a;
	double val;

	t1 = clock();
	for (i = 0; i < ITERATIONS; ++i)
	{
		for (a = 0; a < 360; ++a)
		{

			val = _lookupTable[a];
			/*
			  OptimizeIt!
			*/
			/*val = sin(DEG_TO_RAD(a));*/
		}
	}
	t2 = clock();
	printf("%.1fs\n", (t2 - t1) / (float)CLOCKS_PER_SEC);

	return 0;
}

// normal debug kääntäjällä 6,4 sec.. Release oli 0,0(vaikka laittoi unsigned max iteraatiota) oli optimointia ei releasella voi kokeilla.
// optimoitu debug 0,9 sec Stack kulutus nousi


