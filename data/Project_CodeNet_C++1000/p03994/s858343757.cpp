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
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
int main(){
    string s;cin>>s;
    ll k;cin>>k;
    ll n=(ll)s.size();
    vl num(n);
    rep(i,n){
        num[i]=(ll)(s[i]-'a');
    }
    rep(i,n){
        if(num[i]==0) continue;
        int need=26-num[i];
        if(need<=k){
            num[i]=0;
            k-=need;
        }
    }
    num[n-1]=(num[n-1]+k)%26;
    string ans="";
    rep(i,n){
        ans+=(char)(num[i]+'a');
    }
    cout<<ans<<endl;
    return 0;
}