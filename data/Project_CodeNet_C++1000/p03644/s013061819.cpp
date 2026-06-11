#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
    }else if(2 <= n && n <= 3){
        cout << 2 << endl;
    }else if(4 <= n && n <= 7){
        cout << 4 << endl;
    }else if(8 <= n && n <= 15){
        cout << 8 << endl;
    }else if(16 <= n && n <= 31){
        cout << 16 << endl;
    }else if(32 <= n && n <= 63){
        cout << 32 << endl;
    }else{
        cout << 64 << endl;
    }
    return 0;
}