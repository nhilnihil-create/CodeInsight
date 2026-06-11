#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 100100100100100100;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

int main(){
    ll H,W;
    cin >> H >> W;
    if(H * W % 3 == 0){
        cout << 0 << endl;
        return 0;
    }
    ll ans = INF;
    rep(i,H){
        ll a = i * W,b = ((H - i) / 2) * W,c = (H-i-(H-i)/2) * W;
        ans = min(ans,max({a,b,c})-min({a,b,c}));
        b = (W / 2) * (H-i),c = (W-W/2)*(H-i);
        ans = min(ans,max({a,b,c})-min({a,b,c}));
    }
    swap(H,W);
    rep(i,H){
        ll a = i * W,b = ((H - i) / 2) * W,c = (H-i-(H-i)/2) * W;
        ans = min(ans,max({a,b,c})-min({a,b,c}));
        b = (W / 2) * (H-i),c = (W-W/2)*(H-i);
        ans = min(ans,max({a,b,c})-min({a,b,c}));
    }
    cout << ans << endl;
}
