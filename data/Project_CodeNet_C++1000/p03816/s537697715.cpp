#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    map<int,int> m;
    rep(i,n) m[a[i]]++;
    ll ans = m.size();
    ll sum = 0;
    for(auto t : m){
        sum += t.second - 1;
    }
    if(sum%2!=0) ans--;
    cout << ans << endl;
}