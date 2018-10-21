// Очень сложная задача, нужно было пораскинуть мозгами, чтобы её решить
// У меня это получилось лишь отчасти: программа выводит кучу треугольников просто
// Где-то в коде есть ошибка, но найти её я не могуБ не получается

#include <iostream>
using namespace std;

int high (double x1,double y1,double x2,double y2,double xt, double yd){
    double soot, yt; //соотношение
    soot = (xt-x1)/(x2-x1);
    yt = y1 + soot*(y2*y1);
    if (yt>yd){
        return -1;// то есть точка ниже прямой
    }
    else if (yt<yd){
        return 1; // то есть точка выше прямой
    }
    else {
        return 0;
    }
}

const int o = 8; //количество точек в первом множестве (от слова one)
const int t = 5; //количество точек во втором множестве (от слова two)

int main(){
    int i, d1, d2, d3, fmax(0), fmin(0), fmid(0);
    double xo[o], yo[o], xt[t], yt[t], sum1(0), sum2(0), xmax(0), xmin(0), xmid(0);
    cout << "Введите координаты точек первого множества \n";
    for (i=0; i<o; i++){
        cout << "x = ";
        cin >> xo[i];
        cout << "y = ";
        cin >> yo[i];
    }
    cout << "Введите координаты точек второго множества ; \n";
    for (i=0; i<t; i++){
        cout << "x = ";
        cin >> xt[i];
        cout << "y = ";
        cin >> yt[i];
    }
    for (d1=0; d1<o; d1++){
        for (d2=0; d2<o; d2++){
            for (d3=0; d3<o; d3++){
                if (d1!=d2 && d2!=d3 && d1!=d3){
                    xmax = max(xo[d1], xo[d2]);
                    if (xmax == xo[d1]){
                        fmax = d1;
                    }
                    else {
                        fmax = d2;
                    }
                    xmin = min(xo[d1], xo[d2]);
                    if (xmin == xo[d1]){
                        fmin = d1;
                    }
                    else {
                        fmin = d2;
                    }
                    if (xo[d3]>xmax){
                        xmid = xmax;
                        fmid = fmax;
                        xmax = xo[d3];
                        fmax = d3;
                    }
                    else if (xo[d3]<xmin){
                        xmid = xmin;
                        fmid = fmin;
                        xmin = xo[d3];
                        fmin = d3;
                    }
                    else {
                        xmid = xo[d3];
                    }
                    if (high(xmin, yo[fmin], xmax, yo[fmax], xmid, yo[fmid])==1){
                        for (i=0; i<o; i++){
                            if (xo[i]>xmin && xo[i]<=xmid){
                                if (high(xmin, yo[fmin], xmid, yo[fmid], xo[i], yo[i])==-1 && high(xmin, yo[fmin], xmax, yo[fmax], xo[i], yo[i])==1){
                                    sum1++;
                                }
                            }
                            else if (xo[i]>xmid && xo[i]<xmax){
                                if (high(xmid, yo[fmid], xmax, yo[fmax], xo[i], yo[i])==-1 && high(xmin, yo[fmin], xmax, yo[fmax], xo[i], yo[i])==1){
                                    sum1++;
                                }
                            }
                        }
                        for (i=0; i<t; i++){
                            if (xt[i]>xmin && xt[i]<=xmid){
                                if (high(xmin, yo[fmin], xmid, yo[fmid], xt[i], yt[i])==-1 && high(xmin, yo[fmin], xmax, yo[fmax], xt[i], yt[i])==1){
                                    sum2++;
                                }
                            }
                            else if (xt[i]>xmid && xt[i]<xmax){
                                if (high(xmid, yo[fmid], xmax, yo[fmax], xt[i], yt[i])==-1 && high(xmin, yo[fmin], xmax, yo[fmax], xt[i], yt[i])==1){
                                    sum2++;
                                }
                            }
                        }
                        
                    }
                    else if (high(xmin, yo[fmin], xmax, yo[fmax], xmid, yo[fmid])==-1){
                        for (i=0; i<o; i++){
                            if (xo[i]>xmin && xo[i]<=xmid){
                                if (high(xmin, yo[fmin], xmid, yo[fmid], xo[i], yo[i])==1 && high(xmin, yo[fmin], xmax, yo[fmax], xo[i], yo[i])==-1){
                                    sum1++;
                                }
                            }
                            else if (xo[i]>xmid && xo[i]<xmax){
                                if (high(xmid, yo[fmid], xmax, yo[fmax], xo[i], yo[i])==1 && high(xmin, yo[fmin], xmax, yo[fmax], xo[i], yo[i])==-1){
                                    sum1++;
                                }
                            }
                        }
                        for (i=0; i<t; i++){
                            if (xt[i]>xmin && xt[i]<=xmid){
                                if (high(xmin, yo[fmin], xmid, yo[fmid], xt[i], yt[i])==1 && high(xmin, yo[fmin], xmax, yo[fmax], xt[i], yt[i])==-1){
                                    sum2++;
                                }
                            }
                            else if (xt[i]>xmid && xt[i]<xmax){
                                if (high(xmid, yo[fmid], xmax, yo[fmax], xt[i], yt[i])==1 && high(xmin, yo[fmin], xmax, yo[fmax], xt[i], yt[i])==-1){
                                    sum2++;
                                }
                            }
                        }
                    }
                }
                if (sum1==sum2 && sum1!=0 && sum2!=0){
                    cout << "Найден треугольник с точками ("<< xmin<< ";" << yo[fmin] <<"), ("<< xmid << ";" << yo[fmid]<< "), ("<< xmax << ";" << yo[fmax]<< ")\n";
                }
                sum1 = 0;
                sum2 = 0;
            }
        }
    }
}
