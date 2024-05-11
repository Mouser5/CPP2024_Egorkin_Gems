#pragma once
#include <iostream>
#include <vector>
using namespace std;

void PrintField(vector <vector <char>> field, const int size);
void CreateField(vector < vector <char>>& field, const int size);
void FillField(vector <vector <char>>& field, const int size);
void FromIntToChar(const int temp, char& color);