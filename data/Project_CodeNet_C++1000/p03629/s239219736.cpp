#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

using ll = long long;
using namespace std;
constexpr ll inf = 1e15;

constexpr int MAX_A = 200000;
ll dp[MAX_A+1] = {0};

vector<vector<int> > calcNext(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n+1, vector<int>(26, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string A;
    cin>>A;

    auto next = calcNext(A);
    for (int i = 0; i < A.length(); i++) dp[i] = inf;
    dp[A.length()] = 1;
    for (int i = A.length()-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) if (next[i][j] <= A.length()) dp[i] = min(dp[i], dp[next[i][j]+1]+1);
    }

    string ans = "";
    int pos = 0;
    for (int i = dp[0] - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (dp[next[pos][j] + 1] == i) {
                ans += char(j + 'a');
                pos = next[pos][j] + 1;
                break;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}