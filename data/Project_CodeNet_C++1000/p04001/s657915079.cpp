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
    ll ans = 0;
    string S;
    cin >> S;
    int N = sz(S);
    rep(i, 1<<(N-1)){
        bool used[N];
        fill(used, used+N, false);
        rep(j, N-1) if(i&(1<<j)) used[j+1] = true;
        int now = 0; ll sum = 0;
        while(now < N){
            if(used[now]) ans += sum, sum = 0, used[now] = false;
            else sum = sum*10 + (S[now++]-'0');
        }
        ans += sum;
    }
    cout << ans << endl;
}