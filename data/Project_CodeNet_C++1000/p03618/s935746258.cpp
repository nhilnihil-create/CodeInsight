#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string s;
    cin >> s;
    ll n = s.size();
    ll sum = 1 + n * (n-1) / 2;
    vector<ll> c(26, 0);
    rep(i, 0, n) c[s[i] - 'a']++;
    rep(i, 0, 26) sum -= c[i] * (c[i] - 1) / 2;
    cout << sum << endl;
    return 0;
}