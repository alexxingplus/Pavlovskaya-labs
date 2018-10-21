#include <iostream>
using namespace std;

const string abc = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

int main (){
    int i, k, fh, fm;
    struct train {
        string name;
        int numb;
        int hour;
        int min;
        int time;
        int fletter;
    };
    train mas[7];
    train free;
    for (i=0; i<=7; i++){
        cout << "Введите название пункта назначения\n";
        cin >> mas[i].name;
        cout << "Введите ночер поезда\n";
        cin >> mas[i].numb;
        cout << "Введите время отправления (Часы и минуты двумя числами через пробел)\n";
        cin >> mas[i].hour;
        cin >> mas[i].min;
        mas[i].time = mas[i].min + mas[i].hour*60;
    }
    for (i=0; i<=7; i++){
        for (k=0; k<33; k++){
            if (mas[i].name[0] == abc[k]){
                mas[i].fletter = k;
            }
        }
    }
    for (i=0; i<=7; i++){
        for (k=0; k<7; k++){
            if (mas[i].fletter < mas[i+1].fletter){
                free = mas[i];
                mas[i] = mas[i+1];
                mas[i+1] = free;
            }
        }
    }
    cout << "Введите время (два числа через пробелы)";
    cin >> fh >> fm;
    fm = fm + fh*60;
    for (i=0; i<=7; i++){
        if (mas[i].time > fm){
            cout << "\nНайден поезд, отправляющийся после заданного времени: \n";
            cout << "Место назначения: "<< mas[i].name << ";\n";
            cout << "Номер поезда: "<< mas[i].numb << ";\n";
            cout << "Время отправления: "<< mas[i].hour << ":"<< mas[i].min<<";\n";
        }
    }
    return 0;
}
