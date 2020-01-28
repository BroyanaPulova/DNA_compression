#pragma once
#include "EncodeHelper.h"
#include<queue>
#include<sstream>
#include<map>

class Huffman : public CodingAlgorithm
{
	class HuffmanNode : public Node
	{
	public:
		float rateValue;

		HuffmanNode() :Node()
		{
		}

		HuffmanNode(Node *left, Node *right, ReferenceSymbol data, float rateValue) : Node()
		{
			this->left = left;
			this->right = right;
			this->data = data;
			this->rateValue = rateValue;
		}

		~HuffmanNode()
		{
		}

		bool operator () (const HuffmanNode* left, const HuffmanNode* right) const
		{
			if (left->rateValue != right->rateValue)
				return left->rateValue > right->rateValue;
			return left->data.symbol < right->data.symbol;
		}
	};

	vector<ReferenceSymbol> *fTable;
	unordered_map<char, Code*> *codeEntity;
	string text;
	HuffmanNode* tree;

public:

	Huffman(string text);
	~Huffman();

	// Inherited via CodingAlgorithm
	virtual string Encode() override;
	virtual string Decode(string code) override;

	string EncodeDNA();
	string DecodeDNA();

	HuffmanNode* BuildTree();
	void RemoveLastItem(multimap<HuffmanNode*, HuffmanNode*, HuffmanNode>* tree, HuffmanNode * node);
	string ShowTable();
};

