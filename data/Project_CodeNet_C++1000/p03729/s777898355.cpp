#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string a,b,c;
    cin >> a >> b >> c;
    int na,nb;
    na = a.length();
    nb = b.length();
    if(a[na-1] == b[0] && b[nb-1] == c[0]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}