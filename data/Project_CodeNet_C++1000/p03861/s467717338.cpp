#include <bits/stdc++.h>
using namespace std;
int main(void){
    long int a,b,x;
    cin >> a >> b >> x;
    long int count=0;

    long int fb= b/x + 1;
    long int fa;
    if(a != 0) fa = ((a - 1) / x) + 1;
    else fa = 0;
    //f(n) = n/x +1 　+ 1 はn=0である場合
    //answer -> f(b) - f(a-1)
    count = fb - fa; 

    cout << count <<endl;

    return 0;
}