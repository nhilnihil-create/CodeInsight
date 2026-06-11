#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,c,cnt,a0,b0,c0;
    cnt = 0;
    cin >> a >> b >> c;


    if(a % 2 == 1 || b % 2 == 1 || c % 2 == 1){
        cout << cnt << endl;
    }else if(a == b && b == c){
        cout << -1 << endl;
    }else{
        while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0){
            a0 = a, b0 = b , c0 = c; 
            a = ( b0 + c0 ) / 2;
            b = ( a0 + c0 ) / 2;
            c = ( a0 + b0 ) / 2;
            cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}