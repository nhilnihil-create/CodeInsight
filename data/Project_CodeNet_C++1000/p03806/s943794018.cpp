#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

struct S {
    int a, b, c;
};

const int UNDEFINED = 1e9;

int N, Ma, Mb;
vector<S> abc;
S total;
vector<vector<vector<int>>> dp;
int ans = UNDEFINED;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >> Ma >> Mb;
    abc.resize(N);
    
    rep(i, N) {
        cin >> abc[i].a >> abc[i].b >> abc[i].c;
        total.a += abc[i].a;
        total.b += abc[i].b;
        total.c += abc[i].c;
    }
    
    dp.resize(N);
    
    rep(i, N) {
        dp[i].resize(total.a + 1);
        
        rep(ii, total.a + 1) {
            dp[i][ii].resize(total.b + 1, UNDEFINED);
        }
    }
    
    rep(i, N) {
        rep(ii, sz(dp[i])) {
            rep(iii, sz(dp[i][ii])) {
                if (i == 0) {
                    if ((ii == abc[i].a) && (iii == abc[i].b)) {
                        dp[i][ii][iii] = abc[i].c;
                    }
                }
                else {
                    dp[i][ii][iii] = dp[i - 1][ii][iii];
                    
                    if ((ii == abc[i].a) && (iii == abc[i].b)) {
                        dp[i][ii][iii] = min(dp[i][ii][iii], abc[i].c);
                    }
                    else if ((ii > abc[i].a) && (iii > abc[i].b)) {
                        dp[i][ii][iii] = min(dp[i][ii][iii], dp[i - 1][ii - abc[i].a][iii - abc[i].b] + abc[i].c);
                    }
                }
            }
        }
    }
    
    rep(i, N) {
        reps(ii, 1, sz(dp[i])) {
            reps(iii, 1, sz(dp[i][ii])) {
                if (((double)Ma / Mb) == ((double)ii / iii)) {
                    ans = min(ans, dp[i][ii][iii]);
                }
            }
        }
    }
    
    cout << ((ans == UNDEFINED) ? -1 : ans) << endl;
    return 0;
}
