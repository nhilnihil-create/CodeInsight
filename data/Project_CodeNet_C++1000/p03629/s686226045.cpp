#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    string S;
    cin >> S;
    int N = sz(S);
    int dp[N+1], next[N+1][26];
    fill(dp, dp+N+1, inf);
    dp[N] = 0;
    fill(next[N], next[N]+26, -1);
    rep3(i, N-1, 0){
        rep(j, 26) next[i][j] = next[i+1][j];
        next[i][S[i]-'a'] = i+1;
    }
    rep3(i, N-1, 0){
        rep(j, 26){
            if(next[i][j] == -1) chmin(dp[i], 0);
            else chmin(dp[i], dp[next[i][j]]+1);
        }
    }
    int n = dp[0], now = 0;
    string ans;
    rep(i, n){
        rep(j, 26){
            if(dp[next[now][j]] == n-i-1){
                ans += 'a'+j;
                now = next[now][j];
                break;
            }
        }
    }
    rep(j, 26){
        if(next[now][j] == -1){
            ans += 'a'+j;
            break;
        }
    }
    cout << ans << endl;
}