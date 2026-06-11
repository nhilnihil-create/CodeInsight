#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N;
    ll L;
    cin >> N >> L;
    ll a[N];
    rep(i, N) cin >> a[i];
    int c = 0;
    rep(i, N-1){
        if(a[i]+a[i+1] >= L) c = i+1;
    }
    if(c == 0) cout << "Impossible" << endl;
    else{
        cout << "Possible" << endl;
        rep2(i, 1, c-1) cout << i << endl;
        rep3(i, N-1, c+1) cout << i << endl;
        cout << c << endl;
    }
}