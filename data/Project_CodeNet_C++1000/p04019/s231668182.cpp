#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

string S;
int main() {
    cin >> S;

    map<char, ll> mp;
    rep(i, S.size()) {
        mp[S[i]]++;
    }

    // 左右の動き
    ll w = mp['W'];
    ll e = mp['E'];
    ll n = mp['N'];
    ll s = mp['S'];

    ll judge1 = false;
    if (w == 0 && e == 0) {
        judge1 = true;
    } else if (w > 0 && e > 0) {
        judge1 = true;
    }

    ll judge2 = false;
    if (n == 0 && s == 0) {
        judge2 = true;
    } else if (n > 0 && s > 0) {
        judge2 = true;
    }

    if (judge1 && judge2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}