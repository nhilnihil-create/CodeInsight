#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int dfs(const vector<vector<int>>& losers, int winner) {
    vector<int> depth;
    for (auto& l : losers[winner]) {
        depth.push_back(dfs(losers, l));
    }
    sort(all(depth));
    reverse(all(depth));
    int res = 0;
    rep(i, 0, depth.size()) {
        chmax(res, depth[i] + i + 1);
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N - 1);
    for (auto& a : A) {
        cin >> a;
        --a;
    }
    vector<vector<int>> losers(N);
    rep(i, 0, N - 1) {
        losers[A[i]].push_back(i + 1);
    }
    cout << dfs(losers, 0) << endl;
    return 0;
}