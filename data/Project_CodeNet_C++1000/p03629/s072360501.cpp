#include <bits/stdc++.h>
using namespace std;

bool chmin(int& a, const int b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

string S;
int N;

int nxt[200200][26];
vector<int> idxs[26];
void build() {
    for (int i = 0; i < N; ++i) {
        idxs[S[i] - 'a'].emplace_back(i);
    }
    memset(nxt, 0xff, sizeof(nxt));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 26; ++j) {
            auto itr = lower_bound(idxs[j].begin(), idxs[j].end(), i);
            if (itr == idxs[j].end()) continue;
            nxt[i][j] = *itr;
        }
    }
}

int dp[200200];
int rec(int idx) {
    if (idx >= N) return 1;
    if (dp[idx] != -1) return dp[idx];
    int ret = 1 << 30;
    for (int i = 0; i < 26; ++i) {
        int nxt_idx = nxt[idx][i];
        if (nxt_idx == -1) {
            chmin(ret, 1);
        } else {
            chmin(ret, rec(nxt_idx + 1) + 1);
        }
    }
    return dp[idx] = ret;
}

string recover(int K) {
    int cur = 0;
    string res = "";
    while (K--) {
        int mn = 1 << 30, frm = -1;
        for (int i = 0; i < 26; ++i) {
            int nxt_idx = nxt[cur][i];
            int val = nxt_idx == -1 ? 0 : rec(nxt_idx + 1);
            if (chmin(mn, val)) {
                frm = i;
            }
        }
        cur = nxt[cur][frm] + 1;
        // cerr << mn << ' ' << cur << endl;
        res += (char)('a' + frm);
    }
    return res;
}

signed main() {
    cin >> S;
    N = S.size();
    build();
    memset(dp, 0xff, sizeof(dp));
    int K = rec(0);
    // cerr << K << endl;
    // for (int i = 0; i <= N; ++i) cerr << dp[i] << " \n"[i == N];
    cout << recover(K) << endl;
}
