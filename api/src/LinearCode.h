#pragma once
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

class LinearCode
{
public:
	LinearCode();
	~LinearCode();

	string* CalculateMatrix(int64_t n, int64_t m);
private:
	bool nextComb(int n, int k, int *comb);
	string* Combinations(int m, int n, int*B);
};

