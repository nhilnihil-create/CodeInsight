#include<iostream>
#include<vector>
#include<string>
#include<map>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<ll> X(N);
    for (auto& x : X) {
        cin >> x;
    }
    vector<map<ll, ll>> mods(M);
    rep(i, 0, N) {
        ++mods[X[i] % M][X[i]];
    }
    ll ans = 0;
    rep(m, 0, M / 2 + 1) {
        if (m == (M - m) % M) {
            ll cnt = 0;
            for (auto i : mods[m]) {
                cnt += i.second;
            }
            ans += cnt / 2;
        }
        else {
            ll cnt1 = 0, pair1 = 0;
            for (auto i : mods[m]) {
                cnt1 += i.second;
                pair1 += i.second / 2;
            }
            ll cnt2 = 0, pair2 = 0;
            for (auto i : mods[M - m]) {
                cnt2 += i.second;
                pair2 += i.second / 2;
            }
            ll min_cnt = min(cnt1, cnt2);
            ans += min_cnt;
            cnt1 -= min_cnt;
            cnt2 -= min_cnt;
            if (cnt1) {
                ans += min(cnt1 / 2, pair1);
            }
            else {
                ans += min(cnt2 / 2, pair2);
            }
        }
    }
    cout << ans << endl;
    return 0;
}   