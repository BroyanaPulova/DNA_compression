#pragma once
#include<unordered_map>
#include "CodingAlgorithm.h"
#include <algorithm>
#include <array>
#include <vector>

class Code
{
public:
	ReferenceSymbol symbol;
	int value;
	int lenght;
	string codeValue;
};

class EncodeHelper
{
public:
	static unordered_map<char, Code*> *GenerateCodeTable(Node * root);
	static vector<ReferenceSymbol> *CalculateFrequency(string text);

private:
	static void PassTree(Node * node, int value, int count, string codeValue, unordered_map<char, Code*>* codeEntity);
};

