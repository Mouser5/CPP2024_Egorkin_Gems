#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void ChekField() {

}

void FromIntToChar(const int temp,char & color) {
    if (temp == 1) {
        color = 'R';
        return;
    }
    if (temp == 2) {
        color = 'B';
        return;
    }
    if (temp == 3) {
        color = 'G';
        return;
    }
    if (temp == 4) {
        color = 'O';
        return;
    }
    if (temp == 5) {
        color = 'Y';
        return;
    }
    color = 'P';
    return;
 }

void FillField(vector <vector <char>>& field, const int size) {
    int temp = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp = rand() % 6 + 1;
            FromIntToChar(temp, field[i][j]);
        }
    }
}

void CreateField(vector < vector <char>> &field, const int size) {
    field.resize(size);
    for (int i = 0; i < size; i++) {
        field[i].resize(size);
    }
}

void PrintField(vector <vector <char>> field,  const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << field[i][j]<<" ";
        }
        cout << endl;
    }
}




int main()
{
    vector <vector <char>> field;
    int size = 3;
    CreateField(field, size);
    FillField(field, size);
    PrintField(field, size);
}

