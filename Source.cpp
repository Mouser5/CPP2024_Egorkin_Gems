#include "Header.h"

struct Radius
{
    int leng = 3;
    int type; // ++,-+,--,+-
};

void Convert(char& color) {
    if (color == 'R') {
        color = '1';
        return;
    }
    if (color == 'B') {
        color = '2';
        return;
    }
    if (color == 'G') {
        color = '3';
        return;
    }
    if (color == 'O') {
        color = '4';
        return;
    }
    if (color = 'Y') {
        color = '5';
        return;
    }
    color = '6';
    return;
}

void PrintBon(vector <vector <char>>& field, vector <Bonus>& bonuses, int size) {
    Radius rad;
    srand(time(0));
    for (int i = 0; i < bonuses.size(); i++) {
        int rad_row=0, rad_col=0;
        do
        {
            do {
                rad.type = rand() % 4 + 1;
                do {
                    if ((rad.type == 1) || (rad.type == 4))
                        rad_row = rand() % rad.leng;
                    else
                        rad_row = -rand() % rad.leng;

                } while ((bonuses[i].x + rad_row >= size) || (bonuses[i].x + rad_row < 0));
                if ((rad.type == 1) || (rad.type == 2))
                    rad_col = rad.leng - abs(rad_row);
                else
                    rad_col = -(rad.leng - abs(rad_row));
            } while ((bonuses[i].y + rad_col >= size) || (bonuses[i].y + rad_col < 0));
        }while((field[bonuses[i].x + rad_row][bonuses[i].y + rad_col] == 'Q')|| (field[bonuses[i].x + rad_row][bonuses[i].y + rad_col] == '1') || (field[bonuses[i].x + rad_row][bonuses[i].y + rad_col] == '2') || (field[bonuses[i].x + rad_row][bonuses[i].y + rad_col] == '3') || (field[bonuses[i].x + rad_row][bonuses[i].y + rad_col] == '4') || (field[bonuses[i].x + rad_row][bonuses[i].y + rad_col] == '5') || (field[bonuses[i].x + rad_row][bonuses[i].y + rad_col] == '6'));
        if (bonuses[i].type == 1) {
            field[bonuses[i].x + rad_row][bonuses[i].y + rad_col] = 'Q';
        }
        else
            Convert(field[bonuses[i].x + rad_row][bonuses[i].y + rad_col]);// 'W';
       
    }
    bonuses.clear();
}

void FromIntToChar(const char temp, char& color) {
    if (temp == '1') {
        color = 'R'; //82 88
        return;
    }
    if (temp == '2') {
        color = 'B'; //66 72
        return;
    }
    if (temp == '3') {
        color = 'G'; //71 77
        return;
    }
    if (temp == '4') {
        color = 'O'; //79 85
        return;
    }
    if (temp == '5') {
        color = 'Y'; //89 95
        return;
    }
    color = 'P';    //80 86
    return;
}

void FillField(vector <vector <char>>& field, const int size) {
    int temp = 0;
    char temp_c;
    srand(time(0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp = rand() % 3 + 49;
            temp_c = temp;
            FromIntToChar(temp_c, field[i][j]);
        }
    }
}

void CreateField(vector < vector <char>>& field, const int size) {
    field.resize(size);
    for (int i = 0; i < size; i++) {
        field[i].resize(size);
    }
}

void PrintField(vector <vector <char>> field, const int size) {
    cout << " ";
    for (int i = 1; i <= size; i++) {
        cout <<" "<< i;
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < size; j++) {
            if ((field[i][j] <= 54) && (field[i][j] >= 49))
                cout << "W ";
            else
                cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

void DeleteGems(vector <vector <char>>& field, int size, int col, int row, int count, int type) {
    if (type == 1) {
        for (int i = 0; i < count; i++) {
            field[row][col + i] += 6;
        }
    }
    if (type == 2) {
        for (int i = 0; i < count; i++) {
            field[row + i][col] += 6;
        }
    }
}

void ClearGems(vector <vector <char>>& field, const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((field[i][j] != 'R') && (field[i][j] != 'G') && (field[i][j] != 'B') && (field[i][j] != 'Y') && (field[i][j] != 'O') && (field[i][j] != 'P')&&(field[i][j]!='Q') && (field[i][j] != '1') && (field[i][j] != '2') && (field[i][j] != '3') && (field[i][j] != '4') && (field[i][j] != '5') && (field[i][j] != '6'))
                field[i][j] = ' ';
        }
    }
}

void FallGems(vector <vector <char>>& field, const int size) {
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < size; j++) {
            if (field[i][j] == ' ')
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
        while (k<size)
        {
            if (field[k][i] != ' ')
                break;
            int temp = rand() % 3 + 49;
            char temp_c = temp;
            FromIntToChar(temp_c, field[k][i]);
            k++;
        }
    }
}

void CheckRow(vector <vector <char>>& field, const int size, const int row, bool& NewField, vector<Bonus>& bonuses) {
    int count = 0;
    for (int i = 0; i < size - 2; i++) {
        if((field[row][i]!='Q')&&(field[row][i]!='W')){
            if (((abs(field[row][i] - field[row][i + 1]) == 0) || (abs(field[row][i] - field[row][i + 1]) == 6)) && ((abs(field[row][i] - field[row][i + 2]) == 0) || (abs(field[row][i] - field[row][i + 2]) == 6))) {
                count = 3;
                for (int j = i + 3; j < size; j++) {
                    if ((abs(field[row][i] - field[row][j]) == 0) || (abs(field[row][i] - field[row][j]) == 6))
                    {
                        count++;
                        bonuses.resize(bonuses.size() + 1);
                        bonuses.back() = { row, i + rand() % count, rand() % 2 + 1 };
                    }
                    else
                        break;
                }
                DeleteGems(field, size, i, row, count, 1);
                i += count;
                NewField = true;
            }
        }

    }
}

void CheckCol(vector <vector <char>>& field, const int size, const int col, bool& NewField,vector<Bonus>& bonuses) {
    int count = 0;
    for (int i = 0; i < size - 2; i++) {
        if ((field[i][col] != 'Q') && (field[i][col] != 'W')){
            if ((field[i][col] == field[i + 1][col]) && (field[i][col] == field[i + 2][col])) {
                count = 3;
                for (int j = i + 3; j < size; j++) {
                    if (field[i][col] == field[j][col])
                    {
                        count++;
                        bonuses.resize(bonuses.size() + 1);
                        bonuses.back() = { i + rand() % count, col, rand() % 2 + 1 };
                    }
                    else
                        break;
                }
                DeleteGems(field, size, col, i, count, 2);
                i += count;
                NewField = true;
            }
        }
    }
}

void ActBomb(vector <vector <char>>& field, const int size, int x, int y) {
    FromIntToChar(field[x][y], field[x][y]);
    int row, col;
    for (int i = 0; i < 4; i++) {
        do
        {
            row = rand() % size;
            col = rand() % size;
        } while ((field[row][col] == field[x][y]) && ((abs(row - x)<2) || (abs(col - y)<2)));
        field[row][col] = field[x][y];
    }
}

void ActRecol(vector<vector<char>>& field, const int size, int x, int y) {
    field[x][y] = ' ';
    int row, col;
    for (int i = 0; i < 4; i++) {
        do
        {
            row = rand() % size;
            col = rand() % size;
        } while (field[row][col] == ' ');
        field[row][col] = ' ';
    }
}

void ActBon(vector <vector<char>>& field, const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (field[i][j] == 'Q')
                ActBomb(field, size, i, j);
            if ((field[i][j] <= 54) && (field[i][j] >= 49))
                ActBomb(field, size, i, j);
        }
    }
}

void CheckField(vector <vector <char>>& field, const int size) {
    bool NewField = false;
    vector <Bonus> bonuses;
    for (int i = 0; i < size; i++) {
        CheckCol(field, size, i, NewField,bonuses);
    }

    for (int i = 0; i < size; i++) {
        CheckRow(field, size, i, NewField,bonuses);
    }
    if (!NewField)
        return;
    if (bonuses.size() > 0) {
        PrintBon(field,bonuses,size);
    }
    ClearGems(field, size);
    PrintField(field, size);
    ActBon(field, size);
    PrintField(field, size);
    FallGems(field, size);
    PrintField(field, size);
    CheckField(field, size);
}

void SwapPos(vector <vector<char>>& field, int size) {
    int row1, col1, row2, col2;
    cin >> row1 >> col1 >> row2 >> col2;
    col1 -= 1; row1 -= 1; col2 -= 1; row2 -= 1;
    if ((((abs(col1 - col2) == 1) && (row1 = row2)) || ((col1 == col2) && (abs(row1 - row2) == 1))) && (col1 < size) && (row1 < size) && (col2 < size) && (row2 < size)) {
        swap(field[col1][row1], field[col2][row2]);
        CheckField(field, size);
    }
    else {
        cout << "Erorr" << endl;
        PrintField(field, size);
        SwapPos(field, size);
    }
    SwapPos(field, size);
}

