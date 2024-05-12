#pragma once
#include <iostream>
#include <vector>

struct Bonus
{
    int x;
    int y;
    int type;// Q-bomb, W-recolor
};


using namespace std;

void PrintField(vector <vector <char>> field, const int size);
void CreateField(vector < vector <char>>& field, const int size);
void FillField(vector <vector <char>>& field, const int size);
void CheckField(vector <vector <char>>& field, const int size);
void SwapPos(vector <vector<char>>& field, int size);