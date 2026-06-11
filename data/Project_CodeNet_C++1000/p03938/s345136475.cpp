#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repi(i,x,n) for(ll i=x;i<(ll)(n);i++)
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
//cin.tie(0);
//ios::sync_with_stdio(false);



signed main(){
    ll n,bmin=0;cin>>n;
    vector<ll> sumi(n),a(n,0),b(n,0);

    rep(i,n){
        ll x;cin>>x;
        sumi.at(x-1)=i;
    }

    ll A=0,B=0,mnb=0;
    rep(i,n){
        if(A+B>=sumi[i]){
            A++;
            B=sumi[i]-A;
        }else{
            B--;
            A=sumi[i]-B;
        }
        a[i]=A;b[i]=B;
        mnb=min(mnb,B);
    }
    mnb--;

    rep(i,n){
        cout<<a[i]-mnb<< (i==n-1 ? '\n':' ');
    }

    rep(i,n){
        cout<<b[i]-mnb<< (i==n-1 ? '\n':' ');
    }


}