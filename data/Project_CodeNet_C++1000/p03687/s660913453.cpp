#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_ll.hpp>
//typedef boost::multiprecision::cpp_ll ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
string alp="abcdefghijklmnopqrstuvwxyz";
#define endl "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


int main(){
    string s;cin>>s;
    vector<ll> v[26];
    unordered_map<char,ll> mp;
    rep(i,0,alp.size()-1){
        mp[alp[i]]=i;
    }
    rep(i,0,s.size()-1){
        v[mp[s[i]]].pb(i);
    }
    ll ans=inf;
    rep(i,0,25){
        if(v[i].size()==0){
            continue;
        }
        if(v[i].size()==1){
            ans=min(ans,max(v[i][0],s.size()-1-v[i][0]));
            continue;
        }
        ll maxi=-1;
        rep(j,0,v[i].size()-1){
            if(j==0){
                maxi=max(maxi,v[i][j]);
                maxi=max(maxi,v[i][j+1]-v[i][j]-1);
            }else if(j==v[i].size()-1){
                maxi=max(maxi,s.size()-1-v[i][j]);
            }else{
                maxi=max(maxi,v[i][j+1]-v[i][j]-1);
            }
        }
        ans=min(ans,maxi);
    }
    cout<<ans<<endl;
    return 0;
}




