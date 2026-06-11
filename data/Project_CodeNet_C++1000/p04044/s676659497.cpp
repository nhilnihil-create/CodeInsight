#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n, l;
    cin >> n >> l;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    sort(s.begin(),s.end());
    string ans = "";
    rep(i,n) ans += s[i];
    cout << ans << endl;
    return 0;
}