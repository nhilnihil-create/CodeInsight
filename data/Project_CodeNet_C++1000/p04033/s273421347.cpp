#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int a, b;
    while (cin >> a >> b){
        //一正一负必有零；
        if (a <= 0 && b >= 0) cout << "Zero" << endl;
        //判断二者为负的情况；
        else if (a < 0){
            if ((b - a + 1) % 2 == 0) cout << "Positive" << endl;
            else cout << "Negative" << endl;
        }
        else cout << "Positive" << endl;
    }
    return 0;
}