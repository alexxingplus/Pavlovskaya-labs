#include <iostream>
#include <fstream>
using namespace std;

const int num = 15; //Максимальное количество структур

int main()
{
    int i(0), maxn(0), ch;
    const char* text = "/Users/alexxingplus/Desktop/Учеба/univ/homework/homework/text.txt";
    struct scan_info{
        char model [25];
        int price;
        double x_size;
        double y_size;
        int optr;
        int grey = 0;
    };
    ifstream in (text, ios::binary);
    scan_info mass[num];
    for (i=0; i<num; i++){
        in.read((char*)&mass[i], sizeof(mass[i]));
    }
    in.close();
    while (i<num){
        if (mass[i].grey == 0){
            maxn=i;
            cout << "Введите данные планшетного сканера \n Наименование модели:";
            cin >> mass[i].model;
            cout << "Цена:";
            cin >> mass[i].price;
            cout << "Горизонтальный размер области сканирования:";
            cin >> mass[i].x_size;
            cout << "Вертикальный размер области сканирования:";
            cin >> mass[i].y_size;
            cout << "Оптическое разрешение:";
            cin >> mass[i].optr;
            cout << "Число градаций серого:";
            cin >> mass[i].grey;
            cout << "Хотите ли ввести данные еще одного планшетного сканера?\n 0-Нет   1-Да\n";
            cin >> ch;
            if (ch==1){
                i++;
            }
            else if (ch==0){
                i=i+num;
            }
            else cout << "Вы что-то не то ввели, друг мой\n";
        }
    }
    ofstream out (text, ios::binary);
    out.write((char*)&maxn, sizeof(2));
    for (i=0; i<num; i++){
        out.write((char*)&mass[i], sizeof(mass[i]));
    }
    return 0;
}
