#include "ShannonFano.h"

ShannonFano::ShannonFano(string text)
{
	this->text = text;
	this->fTable = new vector<ReferenceSymbol>();
}

ShannonFano::~ShannonFano()
{
	fTable->clear();

	delete tree;

	for (auto i = codeEntity->begin(); i != codeEntity->end(); i++)
	{
		delete i->second;
	}
}

string ShannonFano::Encode()   
{
	tree = new Node();

	fTable = EncodeHelper::CalculateFrequency(text);   
	BuildTree(tree, fTable, 100);                      
	codeEntity = EncodeHelper::GenerateCodeTable(tree);

	stringstream stream;

	for (int i = 0; (unsigned)i < text.size(); i++)
	{
		Code* code = codeEntity->operator[](text[i]);
		stream << code->codeValue;
	}

	return stream.str();
}

string ShannonFano::Decode(string code)
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

void ShannonFano::BuildTree(Node *node, vector<ReferenceSymbol> *list, float listWeight)
{
	int size = list->size();
	std::string codeValue;
	if (size == 0)//vajna proverka
		return;

	if (size <= 2)
	{
		Node *left = new Node();
		left->data = list->operator[](0);
		left->left = NULL;
		left->right = NULL;
		node->left = left;

		if (size == 2)
		{
			Node *right = new Node();
			right->data = list->operator[](1);
			right->left = NULL;
			right->right = NULL;
			node->right = right;
		}
		else if (size == 1)
		{
			node->left = NULL;
			node->data = list->operator[](0);
		}

		return;
	}
	else
	{
		float sumWeight = 0;
		float middle = listWeight / 2;
		int midIndex = 0;
		int br = 0;

		for (int i = 0; (unsigned)i < list->size() - 1; i++)
		{
			sumWeight += list->operator[](i).rate;

			if (sumWeight <= middle && sumWeight + list->operator[](i + 1).rate > middle)
			{
				float a = middle - sumWeight;
				float b = sumWeight + list->operator[](i + 1).rate - middle;

				if (a > b)
				{
					sumWeight += list->operator[](i + 1).rate;
					midIndex = i + 1;
				}
				else if (a == b)
				{
					if (br % 2 != 0)
					{
						sumWeight += list->operator[](i + 1).rate;
						midIndex = i + 1;
					}
					else
						midIndex = i;
				}
				else
					midIndex = i;
				br++;

				break;
			}
			br++;
		}

		vector<ReferenceSymbol>*leftList = new vector<ReferenceSymbol>(list->begin(), list->begin() + midIndex + 1);
		vector<ReferenceSymbol>*rightList = new vector<ReferenceSymbol>(list->begin() + midIndex + 1, list->end());

		Node *left = new Node();
		left->left = NULL;
		left->right = NULL;
		node->left = left;

		Node *right = new Node();
		right->left = NULL;
		right->right = NULL;
		node->right = right;

		BuildTree(left, leftList, sumWeight);
		BuildTree(right, rightList, listWeight - sumWeight);
	}
}

string ShannonFano::ShowTable()
{
	stringstream text;
	for (auto i = codeEntity->begin(); i != codeEntity->end(); i++)
	{
		text << i->first << "->" << i->second->codeValue << endl;
	}

	return text.str();
}

