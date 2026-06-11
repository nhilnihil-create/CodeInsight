#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    cin >> s;
    string c = "CODEFESTIVAL2016";
    int ans = 0;
    rep(i,s.length()){
        if(s[i] != c[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}