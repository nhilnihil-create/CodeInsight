#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

ll N;
vector<ll> A;

int main() {
    cin >> N;
    A.resize(N);

    rep(i, N) cin >> A[i];

    map<ll, ll> mp;
    rep(i, N) mp[A[i]]++;

    // カードを 0 ~ 2枚にする
    ll second_card = 0;
    for (auto it : mp) {
        if (it.second > 0 && it.second % 2 == 0) {
            mp[it.first] = 2;
            second_card++;
        } 
        else if (it.second % 2 == 1) {
            mp[it.first] = 1;
        }
    }

    ll ans = mp.size();

    // マイナス調整
    if (second_card % 2 != 0) {
        ans--;
    }
    cout << ans << endl;
}