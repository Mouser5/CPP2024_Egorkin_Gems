#include <iostream>
#include <vector>
#include <ctime>
#include "Header.h"
using namespace std;

struct Bonys
{
    int x;
    int y;
    int type;
};

void Prog() {
    vector <vector <char>> field;
    int size = 6;
    CreateField(field, size);
    FillField(field, size);
    PrintField(field, size);
    CheckField(field, size);
    SwapPos(field, size);
}

int main()
{
    Prog();
}

