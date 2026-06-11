#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    string S, T;
    cin >> S >> T;
    int N = S.size(), M = T.size();
    //[0,i)
    int sa[N+1], sb[N+1], ta[M+1], tb[M+1];
    sa[0] = sb[0] = ta[0] = tb[0] = 0;
    rep(i, N){
        sa[i+1] = sa[i], sb[i+1] = sb[i];
        if(S[i] == 'A') sa[i+1]++;
        else sb[i+1]++;
    }
    rep(i, M){
        ta[i+1] = ta[i], tb[i+1] = tb[i];
        if(T[i] == 'A') ta[i+1]++;
        else tb[i+1]++;
    }
    int Q;
    cin >> Q;
    rep(i, Q){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int s = (sa[b]-sa[a-1])+2*(sb[b]-sb[a-1]);
        int t = (ta[d]-ta[c-1])+2*(tb[d]-tb[c-1]);
        if(s%3 == t%3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}