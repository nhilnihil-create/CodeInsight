#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
// #define chmax(x,y) x = max(x,y)
// #define chmin(x,y) x = min(x,y)


template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<vector<int> > calcNext(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n+2, vector<int>(26, n+1));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}

int main() {
    string S;
    cin >> S;
    int n = (int)S.size();
    auto next = calcNext(S);

    vector<int> dp(n+1, 1<<29);
    vector<char> recon(n+1, 'a'); 
    dp[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            if (next[i][j] == n+1) {
                if (dp[i] > 1) {
                    dp[i] = 1;
                    recon[i] = 'a'+j;
                }
            }
            else if (chmin(dp[i], dp[next[i][j] + 1] + 1)) {
                recon[i] = 'a'+j;
            }
        }
    }

    string res = "";
    int index = 0;
    while (index <= n) {
        res += recon[index];
        index = next[index][recon[index]-'a'] + 1;
    }
    cout << res << endl;
    return 0;
}