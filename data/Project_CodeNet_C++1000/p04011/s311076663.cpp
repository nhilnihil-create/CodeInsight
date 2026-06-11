#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n,k,x,y;
    cin >> n >> k >> x >> y;
    if(n > k) cout << x * k + (n - k) * y << endl; 
    else cout << x * n << endl;
    return 0;
}