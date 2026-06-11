#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int w,a,b;
    cin >> w >> a >> b;
    if(a > b){
        int t = a;
        a = b;
        b = t;
    }

    if(a+w > b){
        cout << 0 << endl;
        return 0;
    }
    cout << abs(a+w-b) << endl;
}