#pragma once
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

class SpectreElement
{
public:
	long int Value;
	int count;

	SpectreElement()
		:Value(0), count(-1)
	{
		ValueStr = string("");
	}

	void AddValue(unsigned val);
	void Calculate();
	int GetCountOneBits();
	string ToString(int sizeWord);

	string GetBinaryValue(int sizeWord);

	bool operator<(const SpectreElement other) const
	{
		return this->count < other.count;
	}

	bool operator() (const SpectreElement& element1, const SpectreElement& element2)
	{
		return (element1.count < element2.count);
	}

private:
	long int value = 0;
	string ValueStr;

	int doBinaryJunk(unsigned n, string* value);
};

