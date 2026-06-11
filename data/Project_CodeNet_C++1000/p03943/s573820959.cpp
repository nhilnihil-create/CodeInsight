#include<iostream>
#include<vector>
#include<string>
#include<numeric>
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
    vector<int> cnt(3);
    rep(i, 0, 3) {
        cin >> cnt[i];
    }
    int sum = accumulate(all(cnt), 0);
    rep(i, 0, 3) rep(j, i + 1, 3) {
        if (cnt[i] + cnt[j] == sum - cnt[i] - cnt[j]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}