#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    vector<ll> cnt(26, 0);
    for (auto c: s)
    {
        ++cnt[c-'a'];
    }

    ll ans = 1+(s.size()-1)*s.size()/2;
    rep(i, 0, 26)
    {
        ans -= cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}