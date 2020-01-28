#include "Huffman.h"

Huffman::Huffman(string text)
{
	this->text = text;
}

Huffman::~Huffman()
{
}

string Huffman::Encode()
{
	fTable = EncodeHelper::CalculateFrequency(text);
	tree = BuildTree();
	codeEntity = EncodeHelper::GenerateCodeTable(tree);

	stringstream stream;

	for (int i = 0; (unsigned)i < text.size(); i++)
	{
		Code* code = codeEntity->operator[](text[i]);
		stream << code->codeValue;
	}

	return stream.str();
}

string Huffman::Decode(string code)
{
	Node* currenNode = tree;
	stringstream result;

	for (size_t i = 0; i <= code.size(); i++)
	{
		char symbol = code[i];
		Node* temp = currenNode;

		if (symbol == ONE_ASCII)
			currenNode = currenNode->right;
		else
			currenNode = currenNode->left;


		if (currenNode != NULL)
			continue;

		result << temp->data.symbol;
		currenNode = tree;
		i--;
	}

	return result.str();
}

string Huffman::EncodeDNA()
{	
	Code* A = new Code();
	A->value=00;

	Code* T = new Code();
	A->value=01;

	Code* C = new Code();
	A->value=10;

	Code* G = new Code();
	A->value=11;

	codeEntity->operator[]('A') = A;
	codeEntity->operator[]('T') = A;
	codeEntity->operator[]('C') = A;
	codeEntity->operator[]('G') = A;

	stringstream stream;

	for (int i = 0; (unsigned)i < text.size(); i++)
	{
		Code* code = codeEntity->operator[](text[i]);
		stream << code->codeValue;
	}

	return stream.str();
}

string Huffman::DecodeDNA()
{
	return "";
}

Huffman::HuffmanNode* Huffman::BuildTree()
{
	multimap<HuffmanNode*, HuffmanNode*, HuffmanNode> tree;

	for (auto i = fTable->begin(); i != fTable->end(); i++)
	{
		HuffmanNode* node = new HuffmanNode(NULL, NULL, *i, i->rate);
		tree.insert(std::pair<HuffmanNode*, HuffmanNode*>(node, node));
	}

	while (tree.size() > 1)
	{
		HuffmanNode* right = tree.rbegin()->first;//vzema nai gorniq
		RemoveLastItem(&tree, right);

		HuffmanNode* left = tree.rbegin()->first;//vzema nai gorniq
		RemoveLastItem(&tree, left);

		if (left->data.count == 0 && right->data.count != 0)
			swap(left, right);

		HuffmanNode* parent = new HuffmanNode(left, right, ReferenceSymbol(), right->rateValue + left->rateValue);
		tree.insert(std::pair<HuffmanNode*, HuffmanNode*>(parent, parent));
	}

	return tree.begin()->first;
}

void Huffman::RemoveLastItem(multimap<HuffmanNode*, HuffmanNode*, HuffmanNode> *tree, HuffmanNode* node)
{
	if (tree->size() == 1)
	{
		tree->clear();
		return;
	}
	auto iterator = tree->equal_range(node);
	auto ritem = iterator.first;
	auto it = iterator.first;
	for (; it != iterator.second; ++it) {
		ritem = it;
	}
	tree->erase(ritem);
}

string Huffman::ShowTable()
{
	stringstream text;
	for (auto i = codeEntity->begin(); i != codeEntity->end(); i++)
	{
		text << i->first << "->" << i->second->codeValue << endl;
	}

	return text.str();
}