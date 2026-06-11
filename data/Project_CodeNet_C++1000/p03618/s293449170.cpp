#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    string s; cin >> s;
    vector<ll> cnt(26);
    for(int i = 0; i < 26; i++) {
        cnt[i] = count(s.begin(), s.end(), 'a' + i);
    }
    ll n = s.size();
    ll ans = n * (n - 1) / 2;
    for(int i = 0; i < 26; i++) {
        ans -= (cnt[i] - 1) * cnt[i] / 2;
    }
    cout << ans + 1 << endl;
}