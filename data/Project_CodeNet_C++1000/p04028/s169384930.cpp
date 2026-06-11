#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#ifdef DEBUG
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
#else
#define show(...) 42
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> a) {
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto x : v) os << x << ' ';
    return os;
}
void debug() {
    cerr << '\n';
}
template <typename H, typename... T>
void debug(H a, T... b) {
    cerr << a;
    if (sizeof...(b)) cerr << ", ";
    debug(b...);
}
int dp[5005][5005];
int mod = 1000000007;
inline void add(int &a,int b){
    a += b;
    if(a >= mod) a -= mod;
}
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = (int) s.size();
    dp[0][0] = 1;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(j)add(dp[i+1][j-1],dp[i][j]);
            else add(dp[i+1][j],dp[i][j]);
            add(dp[i+1][j+1],dp[i][j]);
            add(dp[i+1][j+1],dp[i][j]);
        }
    }
    ll inv = (mod + 1) /2;
    ll ans = dp[n][m];
    rep(i,m) (ans *= inv) %= mod;
    cout << ans << endl;
}