#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
signed main(){
    ll n;cin>>n;
    string s;cin>>s;
    string t;cin>>t;
    ll ans=2*n;
    rep(i,n){
        bool f=1;
        rep(j,n-i){
            if(s[i+j]!=t[j])f=0;
        }
        if(f){
            ans=n+i;
            break;
        }
    }
    cout<<ans<<endl;
}