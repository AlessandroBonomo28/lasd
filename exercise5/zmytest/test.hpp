#ifndef MYTEST_HPP
#define MYTEST_HPP
#include <string>
/* ************************************************************************** */




void Raddoppia(const int & n, void* _);
void Concat(const std::string& val, const void* value, std::string acc);
void SommaMinN(const int & n, const void* value, void* acc);
void UpperCase(const std::string& val, void* _);
void MoltMaggN(const float & n, const void* value, void* acc);
void MapPrint(const int& n, void* _);
void MapPrint(const float& n, void* _);
void MapPrint(const std::string& val, void* _);
void Square(const float & n, void* _);
std::string GetRandString(int len);


void mytest();
/* ************************************************************************** */
#endif