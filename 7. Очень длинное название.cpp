#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int i, a(0), max(0);
    string ex;
    char line[1000];
    FILE *text;
    text = fopen("/Users/alexxingplus/Desktop/Учеба/univ/homework/homework/homework/hmm.dat","r");
    fgets(line, 1000, text);
    cout << line << endl;
    for (i=0; i<=1000; i++){
        if (line[i]!= ' '){
            a++;
            if (a>max){
                max = a;
            }
        }
        else if (line[i] == ' ') {
            a = 0;
        }
    }
    cout << "Максимальная длина слова - " << max<< endl;
}
