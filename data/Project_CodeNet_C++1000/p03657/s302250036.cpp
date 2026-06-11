#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int a, b;
    cin>> a >> b;
    if(a%3 == 0 || b%3 == 0 || (a+b)%3 == 0) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}