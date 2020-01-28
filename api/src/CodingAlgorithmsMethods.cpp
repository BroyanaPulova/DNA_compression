#include "CodingAlgorithmsMethods.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <array>
#include "ShannonFano.h"
#include "Huffman.h"
#include <bitset>
#include <stdexcept>

using namespace std;

//namespace CodingAlgorithmsMethods
//{
	    CodingAlgorithm *huffman;
		extern "C" {
			CODINGALGORITHMSMETHODS_API void InitText(string text)
			{
				huffman = new Huffman(text);
			}
		}
		CODINGALGORITHMSMETHODS_API string Encode(string text)
		{
			return huffman->Encode();
		}

		CODINGALGORITHMSMETHODS_API string Decode(string text)
		{
			return huffman->Decode(text);
		}
	
//}

//int main()
//{
//	//string text;
//
//	//try
//	//{ 
//	//	cout << "vavedete tekst" << endl;
//	//	std::getline(std::cin, text);
//
//	//	CodingAlgorithm *katerichka = new Huffman(text);
//	//	string result = katerichka->Encode();
//
//	//	cout << result << endl;
//
//	//	result = katerichka->Decode(result);
//	//	cout << result << endl;
//	//}
//	//catch(...)
//	//{
//	//	cout << "greshchica";
//	//}
//
//	//system("PAUSE");
//
//	//return 0;
//}


