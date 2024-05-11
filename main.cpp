#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void ChekField() {

}

void FillField(vector <vector <int>>& field, const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            field[i][j] = rand() % 6+1;
        }
    }
}

void CreateField(vector < vector <int>> &field, const int size) {
    field.resize(size);
    for (int i = 0; i < size; i++) {
        field[i].resize(size);
    }
}

void PrintField(vector <vector <int>> field,  const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << field[i][j]<<" ";
        }
        cout << endl;
    }
}




int main()
{
    vector <vector <int>> field;
    int size = 3;
    CreateField(field, size);
    FillField(field, size);
    PrintField(field, size);
}

