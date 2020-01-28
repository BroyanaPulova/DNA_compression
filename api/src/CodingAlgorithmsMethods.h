// CodingAlgorithmsMethods.h
#pragma once
#include <string>

#ifndef _NATIVELIB_H_
#define _NATIVELIB_H_

#ifndef CODINGALGORITHMSMETHODS_API
#define CODINGALGORITHMSMETHODS_API
#endif

//#ifdef CODINGALGORITHMSMETHODS_EXPORTS
//#define CODINGALGORITHMSMETHODS_API __declspec(dllexport) 
//#else
//#define CODINGALGORITHMSMETHODS_API __declspec(dllimport) 
//#endif

//#ifdef __cplusplus
extern "C" {
//#endif

//namespace CodingAlgorithmsMethods
//{
//	class CodingAlgorithmsMethods
//	{
	//public:
	     CODINGALGORITHMSMETHODS_API void InitText(std::string text);
		
		CODINGALGORITHMSMETHODS_API std::string Encode(std::string text);

	     CODINGALGORITHMSMETHODS_API std::string Decode(std::string text);
	//};
//}

//#ifdef __cplusplus
}
//#endif

#endif // _NATIVELIB_H_
