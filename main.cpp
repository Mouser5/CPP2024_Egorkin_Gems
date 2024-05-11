#include <iostream>
#include <vector>
#include <ctime>
#include "Header.h"
using namespace std;

void DeleteGems(vector <vector <char>> &field, int size, int col, int row,int count, int type) {
    if (type == 1) {
        for (int i = 0; i < count; i++) {
            field[row][col+i] += 6;
        }
    }
    if (type == 2) {
        for (int i = 0; i < count; i++) {
            field[row+i][col] += 6;
        }
    }
}

void ClearGems(vector <vector <char>>& field, const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((field[i][j] != 'R') && (field[i][j] != 'G') && (field[i][j] != 'B') && (field[i][j] != 'Y') && (field[i][j] != 'O') && (field[i][j] != 'P'))
                field[i][j] = ' ';
        }
    }
}

void FallGems(vector <vector <char>> &field, const int size) {
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < size; j++) {
            if(field[i][j]==' ')
                for (int k = i - 1; k >= 0; k--) {
                    if (field[k][j] != ' ') {
                        swap(field[i][j], field[k][j]);
                        break;
                    }
                }
        }
    }
    int k = 0;
    for (int i = 0; i < size; i++) {
        k = 0;
        while (field[k][i]==' ')
        {
            int temp = rand() % 3 + 1;
            FromIntToChar(temp, field[k][i]);
            k++;
        }
    }
}


void CheckRow(vector <vector <char>>& field, const int size, const int row,bool& NewField) { 
    int count=0;
    for (int i = 0; i < size - 2; i++) {
        if ( (   (field[row][i] == field[row][i + 1])||(field[row][i]-6==field[row][i+1])||(field[row][i]==field[row][i+1]-6)) && ((field[row][i] == field[row][i + 2]) || (field[row][i] - 6 == field[row][i + 2]) || (field[row][i] == field[row][i + 2] - 6))) {
            count = 3;
            for (int j = i + 3; j < size; j++) {
                if (field[row][i] == field[row][j])
                    count++;
                else
                    break;
            }
            DeleteGems(field, size, i, row, count, 1);
            i += count;
            NewField = true;
        }
           
    }
}

void CheckCol(vector <vector <char>>& field,const int size,const int col,bool &NewField) {
    int count = 0;
    for (int i = 0; i < size - 2; i++) {
        if ((field[i][col] == field[i + 1][col]) && (field[i][col] == field[i + 2][col])) {
            count = 3;
            for (int j = i + 3; j < size; j++) {
                if (field[i][col] == field[j][i])
                    count++;
                else
                    break;
            }
            DeleteGems(field, size, col, i, count, 2);
            i += count;
            NewField = true;
        }
    }
}

void CheckField(vector <vector <char>> &field,const int size) {
    bool NewField = false;
    for (int i = 0; i < size; i++) {     
        CheckCol(field, size, i,NewField);
    }

    for (int i = 0; i < size; i++) {
        CheckRow(field, size,i,NewField);
    }
    if (!NewField)
        return;
    ClearGems(field, size);    
    FallGems(field, size);
    CheckField(field, size);
}



int main()
{
    vector <vector <char>> field;
    int size = 9;
    CreateField(field, size);
    FillField(field, size);
    CheckField(field, size);
    PrintField(field, size);

}

