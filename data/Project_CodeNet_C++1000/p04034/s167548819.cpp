#include<iostream>
#include<vector>
#include<string>
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
    vector<int> X(M), Y(M);
    rep(i, 0, M) {
        cin >> X[i] >> Y[i];
        --X[i], --Y[i];
    }
    vector<int> cnt(N, 1);
    vector<bool> exists(N, false);
    exists[0] = true;
    rep(i, 0, M) {
        if (exists[X[i]]) {
            exists[Y[i]] = true;
        }
        --cnt[X[i]];
        ++cnt[Y[i]];
        if (!cnt[X[i]]) {
            exists[X[i]] = false;
        }
    }
    int ans = 0;
    rep(i, 0, N) {
        if (exists[i]) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}