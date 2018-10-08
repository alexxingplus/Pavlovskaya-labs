#include <iostream>
using namespace std;

int main()
{
    double d, xn, xk, x, a , b, c;
    int ai, bi, ci;
    cout << "Введите шаг dX:";
    cin >> d;
    cout << "X начальное - ";
    cin >> xn;
    cout << "X конечное - ";
    cin >> xk;
    cout << "Введите а:";
    cin >> a;
    cout << "Введите b:";
    cin >> b;
    cout << "Введите c:";
    cin >> c;
    ai = int(a);
    bi = int(b);
    ci = int(c);
    for (x=xn ; x<=xk ; x=x+d){
        if (x<5 && c!=0){
            cout <<"Значение при x = "<< x << ": ";
            if (((a||b)^(a||c))!=0){
                cout <<-a*(x*x)-b << endl;
            }
            else{
                cout << int(-a*(x*x)-b) << endl;
            }
        }
        else if (x>5 && c==0){
            cout <<"Значение при x = "<< x << ": ";
            if (((a||b)^(a||c))!=0){
                cout << (x-a)/x << endl;
            }
            else{
                cout << int((x-a)/x) << endl;
            }
        }
        else{
            cout <<"Значение при x = "<< x << ": ";
            if (((a||b)^(a||c))!=0){
                cout << -x/c << endl;
            }
            else{
                cout << int(-x/c) << endl;
            }
        }
    }
    return 0;
}
