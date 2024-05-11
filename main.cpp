#include <iostream>
#include <vector>
#include <ctime>
#include "Header.h"
using namespace std;

void CheckRow(const vector <char> field, const int size,const int col) {
    for (int i = 0; i < size - 2; i++) {
        if ((field[i] == field[i + 1]) && (field[i] == field[i + 2]))
            cout <<"Row :"<< i+1<<"/"<<col+1 << field[i] << endl;
    }
}

void CheckCol(const vector <vector <char>> field,const int size,const int col) {
    for (int i = 0; i < size - 2; i++) {
        if ((field[i][col] == field[i+1][col]) && (field[i][col] == field[i+2][col]))
            cout <<"Col :"<< i+1<<"/" << col + 1 << field[i][col] << endl;
    }
}

void CheckField(vector <vector <char>> &field,const int size) {
    for (int i = 0; i < size; i++) {
        CheckRow(field[i], size,i);
        CheckCol(field, size, i);
    }
}



int main()
{
    vector <vector <char>> field;
    int size = 6;
    CreateField(field, size);
    FillField(field, size);
    PrintField(field, size);
    CheckField(field, size);
}

