#include <iostream>
using namespace std;

const int r = 8;//размерность матрицы
 int main()
{
    int i, j, pr (1), sum (0); //i – строчки, j - столбцы
    int tab[r][r];
    cout << "Введите таблицу построчно \n"; //вводим значения элементов
    for (i=0; i<r; i++){
        for (j=0; j<r; j++){
            cin >>tab[i][j];
        }
    }
    
    for (i=0; i<r; i++){ //сравниваем строчки и столбцы
        for (j=0; j<r; j++){
            if (tab[i][j]!=tab[j][i]){
                pr = pr*0;
            }
            if (j==r-1 && pr==1){
                cout << i+1 << " строчка равна "<< i+1 << " столбцу\n";
            }
            else if (j==r-1 && pr==0){
                pr = 1;
            }
        }
    }
    
    for (i=0; i<r; i++){ //ищем отрицательные элементы и суммы строчек
        for (j=0; j<r; j++){
            if (tab[i][j]<0){
                j=0;
                for (j=0; j<r; j++){
                    sum = sum + tab[i][j];
                }
                cout << "В "<< i+1 << " строчке был найден отрицательный элемент. Сумма строчки равна "<< sum << endl;
                sum = 0;
            }
        }
    }
    return 0;
}
