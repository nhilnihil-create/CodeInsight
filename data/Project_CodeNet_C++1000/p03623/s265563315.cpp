#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int x, a, b;
    cin >> x >> a >> b;
    int A = abs(x - a);
    int B = abs(x - b);
    if(A < B) cout << "A" << endl;
    else cout << "B" << endl;
    return 0;
}