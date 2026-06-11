#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
int main(){
    int n;cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    map<int,int> mp;
    rep(i,n){
        mp[a[i]]++;
    }
    int cnt=0;
    for(auto p:mp){
        if(p.second>1) cnt+=p.second-1;
    }
    if(cnt%2==0) cout << n-cnt << endl;
    else cout << n-cnt-1 << endl;
    return 0;
}