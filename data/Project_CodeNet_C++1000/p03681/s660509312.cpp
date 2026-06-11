#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    ll a,b;
    cin >> a >> b;
    if(abs(a-b)>=2){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    ll now = a;
    rep(i,a){
        ans *= now;
        ans %= mod;
        now--;
    }
    now = b;
    rep(i,b){
        ans *= now;
        ans %= mod;
        now--;
    }
    if(a==b) ans *= 2;
    ans %= mod;
    cout << ans << endl;
    return 0;
}