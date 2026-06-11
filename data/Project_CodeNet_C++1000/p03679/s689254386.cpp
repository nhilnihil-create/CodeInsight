#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int x, a, b;
    cin >> x >> a >> b;
    if(a >= b){
        cout << "delicious" << endl;
        return 0;
    }else if(b - a <= x){
        cout << "safe" << endl;
        return 0;
    }else{
        cout << "dangerous" << endl;
        return 0;
    }
}