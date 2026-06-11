#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    char a, b;
    cin >> a >> b;
    if(a == b) cout << 'H' << endl;
    else cout << 'D' << endl;
    return 0;
}