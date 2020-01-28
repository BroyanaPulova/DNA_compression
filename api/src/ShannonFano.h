#pragma once
#include "EncodeHelper.h"
#include <iostream>
#include <sstream>

class ShannonFano : public CodingAlgorithm
{
	vector<ReferenceSymbol> *fTable;
	unordered_map<char, Code*> *codeEntity;
	string text;
	Node* tree;

public:
	ShannonFano(string text);
	~ShannonFano();

	// Inherited via CodingAlgorithm
	virtual string Encode() override;
	string ShowTable();
	virtual string Decode(string code) override;

	void BuildTree(Node * node, vector<ReferenceSymbol>* list, float listWeight);
};

