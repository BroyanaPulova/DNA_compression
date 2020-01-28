#include "EncodeHelper.h"

unordered_map<char, Code*> *EncodeHelper::GenerateCodeTable(Node *root)
{
	unordered_map<char, Code*> *codeEntity = new unordered_map<char, Code*>();
	PassTree(root, 0, 0, "", codeEntity);

	return codeEntity;
}

vector<ReferenceSymbol> *EncodeHelper::CalculateFrequency(string text)
{
	std::array	<ReferenceSymbol, 128> letter = std::array<ReferenceSymbol, 128>();
	vector<ReferenceSymbol> *fTable = new vector<ReferenceSymbol>();

	for (int i = 0; (unsigned)i < text.size(); i++)
	{
		int c = text[i];  //index 
		letter[c].count++;
		letter[c].symbol = text[i];
	}

	sort(letter.begin(), letter.end());

	int i = 0;
	while (letter[i].count != 0) //����������� �����������
	{
		letter[i].rate = (letter[i].count * 100) / (float)text.size();
		fTable->push_back(letter[i]);

		i++;
	}

	return fTable;
}

void EncodeHelper::PassTree(Node * node, int value, int count, string codeValue, unordered_map<char, Code*> *codeEntity)
{
	if (node == NULL)
	{
		throw exception();
	}

	if (node->left == NULL && node->right == NULL)
	{
		Code *code = new Code();
		code->symbol = node->data;
		code->value = value;
		code->lenght = count;
		code->codeValue = codeValue;

		codeEntity->operator[](code->symbol.symbol) = code;//kod-simvol-bukvichka

		return;
	}

	value = value << 1;
	count++;

	if (node->left != NULL)
	{
		PassTree(node->left, value, count, codeValue + '0', codeEntity);
	}

	if (node->right != NULL)
	{
		value++;
		PassTree(node->right, value, count, codeValue + '1', codeEntity);
	}
}
