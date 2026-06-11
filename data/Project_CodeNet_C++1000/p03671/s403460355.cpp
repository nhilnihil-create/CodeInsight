#include<iostream>
using namespace std;

int main(void){
    int a,b,c = 0;
    cin >> a >> b >> c;
    int m = a+b;
    if(m > b+c){
        m = b+c;
    }
    if(m > c+a){
        m = c+a;
    }
    cout << m;
}