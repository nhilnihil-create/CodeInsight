#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n==1)cout << 1;
    else if(n<4)cout << 2;
    else if(n<8)cout << 4;
    else if(n<16)cout << 8;
    else if(n<32)cout << 16;
    else if(n<64)cout << 32;
    else cout << 64;
}