#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int N;
string S;

// 1 : Sheep, 2 : Wolf, 0 : Unknown

bool dfs(vector<int> &ans, vector<int> &ret, int idx) {
    if (idx == N - 1) {
        if ((ret[idx] == 1 && S[idx] == 'o') || (ret[idx] == 2 && S[idx] == 'x')) {
            if (ret[idx - 1] == ret[0]) {
                ans = ret;
                return true;
            } else {
                return false;
            }
        } else if ((ret[idx] == 2 && S[idx] == 'o') || (ret[idx] == 1 && S[idx] == 'x')) {
            if (ret[idx - 1] != ret[0]) {
                ans = ret;
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    int p = (N + idx - 1) % N, n = idx + 1;
    if ((ret[idx] == 1 && S[idx] == 'o') || (ret[idx] == 2 && S[idx] == 'x')) {
        if (ret[p] && ret[n]) {
            if (ret[p] == ret[n]) return dfs(ans, ret, idx + 1);
            else return false;
        } else if (ret[p]) {
            ret[n] = ret[p];
            return dfs(ans, ret, idx + 1);
        } else if (ret[n]) {
            ret[p] = ret[n];
            return dfs(ans, ret, idx + 1);
        } else {
            vector<int> ret1 = ret, ret2 = ret;
            ret1[p] = ret1[n] = 1;
            ret2[p] = ret2[n] = 2;
            return dfs(ans, ret1, idx + 1) || dfs(ans, ret2, idx + 1);
        }
    } else if ((ret[idx] == 2 && S[idx] == 'o') || (ret[idx] == 1 && S[idx] == 'x')) {
        if (ret[p] && ret[n]) {
            if (ret[p] != ret[n]) return dfs(ans, ret, idx + 1);
            else return false;
        } else if (ret[p]) {
            ret[n] = ((ret[p] == 1) ? 2 : 1);
            return dfs(ans, ret, idx + 1);
        } else if (ret[n]) {
            ret[p] = ((ret[n] == 1) ? 2 : 1);
            return dfs(ans, ret, idx + 1);
        } else {
            vector<int> ret1 = ret, ret2 = ret;
            ret1[p] = ret2[n] = 1;
            ret2[p] = ret1[n] = 2;
            return dfs(ans, ret1, idx + 1) || dfs(ans, ret2, idx + 1);
        }
    } else {
        vector<int> ret1 = ret, ret2 = ret;
        ret1[idx] = 1; ret2[idx] = 2;
        return dfs(ans, ret1, idx) || dfs(ans, ret2, idx);
    }
}

int main() {
    cin >> N >> S;
    vector<int> ans, ret(N, 0);
    if (dfs(ans, ret, 0)) {
        for (auto a : ans) {
            if (a == 1) cout << 'S';
            else cout << 'W';
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}