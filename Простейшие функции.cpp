#include <iostream>
using namespace std;

int st (int a, int b, int c, int d, int e, int f, int g, int h, int a1, int b1, int c1, int d1, int e1, int f1, int g1, int h1){
    if (a==a1 && b==b1 && c==c1 && d==d1 && e==e1 && f==f1 && h==h1){
        return 1;
    }
    else return 0;
}

double mi (int a, int b, int c, int d, int e, int f, int g, int h){
    if (a<0 || b<0 || c<0 || d<0 || e<0 || f<0 || g<0 || h<0){
        return a+b+c+d+e+f+g+h;
    }
    else return 1.5; //Просто случайное число, которое не является целым
}

int main(){
    int mas[8][8], i, k;
    cout << "Введите элементы матрицы\n";
    for (i=0; i<8; i++){
        for (k=0; k<8; k++){
            cin >> mas[i][k];
        }
    }
    for (i=0; i<=7; i++){
        if (st(mas[i][0], mas[i][1], mas[i][2], mas[i][3], mas[i][4], mas[i][5], mas[i][6], mas[i][7], mas[0][i], mas[1][i], mas[2][i], mas[3][i], mas[4][i], mas[5][i], mas[6][i], mas[7][i])==1){
            cout<< i+1 << " столбец равен "<< i+1 << "столбцу \n";
        }
    }
    cout << endl; //просто красиво отделяю одно от другого
    for (i=0; i<=7; i++){
        if (mi(mas[i][0], mas[i][1], mas[i][2], mas[i][3], mas[i][4], mas[i][5], mas[i][6], mas[i][7])==1.5){
            cout << i+1 << " строка не содержит ни одного отрицательного элемента\n";
        }
        else{
            cout << "В "<< i+1 << " строке найден отрицательный элемент. Сумма равна "<< int(mi(mas[i][0], mas[i][1], mas[i][2], mas[i][3], mas[i][4], mas[i][5], mas[i][6], mas[i][7]))<< endl;;
        }
    }
}
