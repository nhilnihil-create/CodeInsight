#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
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
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N;
    cin >> N;
    int a[N], b[N];
    string s;
    cin >> s;
    rep(i, N) a[i] = (s[i] == 'x');
    rep(p, 2) rep(q, 2){
        b[0] = p, b[1] = q, b[2] = a[1]^p^q;
        //b[i]を順に決めていく
        rep2(i, 3, N-1){
            b[i] = b[i-3]^(a[i-1]!=a[i-2]);
        }
        bool able = true;
        rep(i, N){
            if(b[(i+N-1)%N]^b[i]^b[(i+1)%N] != a[i]) able = false;
        }
        if(able){
            rep(i, N){
                if(b[i]) cout << 'W';
                else cout << 'S';
            }
            cout << endl;
            return 0;
        }
        elif(p&q) cout << -1 << endl;
    }
}