#include <iostream>
using namespace std;
int main() {
    int n,c=0,i=0,a;
    cin >> n;
    a=n;
    for( i=0;n>0;i++) {
        c = n % 10;
        n /= 10;
    }
    if(i==3){
        cout<<'A'<<'B'<<'C'<<a;
    }else if(i==2)
        cout<<'A'<<'B'<<a;
    else
        cout<<'A'<<a;
}

