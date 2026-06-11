#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

const int MAX_N = 100000;

vector<vector<int>> win(MAX_N, vector<int>(0));

int solve(int x) {
    if (win[x].size() == 0) return 0;
    vector<int> v(0);
    rep(i, win[x].size()) v.push_back(solve(win[x][i]));
    sort(v.begin(), v.end());
    int ret = -1;
    rep(i, v.size()) {
        if (v[i] > ret) ret = v[i] + 1;
        else ret++;
    }
    return ret;
}

int main() {
    int N, a;
    cin >> N;
    rep(i, N - 1) {
        cin >> a;
        win[a - 1].push_back(i + 1);
    }
    /*
    rep(i, N) {
        cout << i << " ";
        rep(j, win[i].size()) cout << win[i][j] << " ";
        cout << endl;
    }
    */
    cout << solve(0) << endl;
}