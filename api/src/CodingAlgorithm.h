#pragma once
#include <string>

using namespace std;

#define ONE_ASCII 49

class CodingAlgorithm
{
public:

	virtual string Encode() = 0;
	virtual string Decode(string code) = 0;
};

class ReferenceSymbol
{
public:
	char symbol;
	int  count;
	float rate;

	ReferenceSymbol()
	{
		symbol = '?';
		count = 0;
		rate = 0.0;
	}

	~ReferenceSymbol()
	{
	}

	bool operator < (const ReferenceSymbol& symbol) const
	{
		if (count != symbol.count)
			return count > symbol.count;
		
		return this->symbol < symbol.symbol;
	}
};

class Node
{
public:
	ReferenceSymbol data;
	Node *left;
	Node *right;
};