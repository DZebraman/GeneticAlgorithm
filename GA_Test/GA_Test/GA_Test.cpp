// GA_Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <bitset>
#include <stdint.h>
#include <time.h>       /* time */
#include <iostream>
#include <stdio.h>
using namespace std;



struct testData{
	testData breed(testData other, float ratio) {
		testData child;
		for (int i = 0; i < testbits.size(); ++i) {
			if (rand()%10 > 4) {child.testbits[i] = testbits[i];}
			else {child.testbits[i] = other.testbits[i];}
		}
		for (int i = 0; i < child.testbits.size(); ++i) {
			if (rand() % 1000 <= 5) {child.testbits[i] = !child.testbits[i];}
		}
		child.speed = child.testbits.to_ulong();
		return child;
	}

	float fitness;
	float speed;

	bitset<(sizeof(float)*8)> testbits;
	//butts testButts;
};

int main()
{
	vector<testData> tests;

	srand(time(NULL));

	int generations = 100;
	float avgFitness;
	int target = 20;

	for (int i = 0; i < 4000; ++i) {
		testData megaButt;
		megaButt.speed = rand() % 7000;
		megaButt.testbits = bitset<(sizeof(float) * 8)>(megaButt.speed);
		tests.push_back(megaButt);
	}

	for (int z = 0; z < generations; ++z) {
		vector<testData*> breedPool;
		vector<testData> nextGen;

		/*int min = tests[0].speed, max = tests[0].speed;
		for (int i = 1; i < tests.size(); ++i) {
			if (tests[i].speed < min)
				min = tests[i].speed;
			else if (tests[i].speed > max)
				max = tests[i].speed;
		}*/
		avgFitness = 0;
		for (int i = 0; i < tests.size(); ++i) {
			float deviation = abs(tests[i].speed - target);

			if(deviation != 0) tests[i].fitness = 1 / deviation;
			else tests[i].fitness = 1;

			avgFitness += tests[i].fitness;

			for (int k = 0; k < 100 * tests[i].fitness; ++k) {
				breedPool.push_back(&tests[i]);
			}
		}
		avgFitness /= tests.size();
		for (auto t : tests) {
			int random = rand() % breedPool.size();
			nextGen.push_back(breedPool[random]->breed(t,random));
			//breedPool.erase(breedPool.begin(), breedPool.begin() + random);
		}
		swap(tests, nextGen);
	}

	//testData megaButt;
	//megaButt.speed = 80000;
	//megaButt.testbits = bitset<(sizeof(float)*8)>(megaButt.speed);
	//megaButt.speed = megaButt.testbits.to_ulong();

	//testData megaButt2;
	//megaButt2.speed = 90000;
	//megaButt2.testbits = bitset<(sizeof(float) * 8)>(megaButt2.speed);

	//testData num3 = megaButt.breed(megaButt2,0.5f);

	//for (int i = 0; i < megaButt.testbits.size(); ++i) {
	//	if (rand() % 1000 <= 5) {
	//		megaButt.testbits[i] = !megaButt.testbits[i];
	//	}
	//}

	////megaButt.testbits[3] = 1;
	//megaButt.speed = megaButt.testbits.to_ulong();
	////megaButt.testbits = bitset<8>(megaButt.testButts.test[2]);E

	for (int i = 0; i < tests.size(); ++i) {
		float deviation = abs(tests[i].speed - target);

		if (deviation != 0) tests[i].fitness = 1 / deviation;
		else tests[i].fitness = 1;
	}

	////tests.push_back(megaButt);
	cout << avgFitness;
    return 0;
}

