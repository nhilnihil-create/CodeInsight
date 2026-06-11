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
    ll x,y;cin>>x>>y;
    ll ans=0;
    if(x*y>0){
        if(y<x){
            ans=x-y+2;
        }
        if(y>x){
            ans=y-x;
        }
    }else if(x*y==0){
        if(x==0){
            if(y<0)ans=-y+1;
            else ans=y;
        }else{
            if(y<x){
                ans=x-y+1;
            }
            if(y>x){
                ans=y-x;
            }
        }
    }else{
        if(x>y){
            if(x>=-y){
                ans=x+y+1;
            }else{
                ans=-y-x+1;
            }
        }
        if(x<y){
            if(-x<=y){
                ans=1+y+x;
            }else{
                ans=-x-y+1;
            }
        }
    }
    cout<<ans<<endl;
}