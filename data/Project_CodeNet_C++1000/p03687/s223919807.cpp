#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
using ll=long long;
using ld=long double;
const ll INF = 1LL<<60;
const ll mod=1e9+7;
using namespace std;
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
pair<ll,ll> z[30];
map<ll,ll>p;
int main(){
    ll cnt,ans=1e11;
    string s,t;
    cin>>s;
    rep(i,0,26){
        char x=i+'a';
        t=s;
        cnt=0;
        while(cnt<s.length()){
            p.clear();
            ll tl=t.length();
            rep(j,0,tl)p[t[j]-'a']++;
            if(p.size()==1)break;
            rep(j,1,tl)if(t[j]==x)t[j-1]=x;
            t.erase(tl-1);
            cnt++;
        }
        ans=min(ans,cnt);
    }
    cout<<ans;
}