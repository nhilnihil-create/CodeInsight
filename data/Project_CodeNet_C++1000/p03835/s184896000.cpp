// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで
 
#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1001001001
#define ll int
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;
 
int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
 
    int a,b,c,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str;
    ll k;
    cin>>k>>n;
    a=n;
    ll v[k+1];
    ll w[(k+1)*(k+1)];
    rep(i,k+1){
        v[i]=i;
        //cout<<i<<" ";
    }
    //ln;
    map<ll,ll> ma;

    rep(i,k+1){
        rep(j,k+1){
            ma[i+j]++;
        }
    }
    //ln;
    map<ll,ll> mp;

    rep(j,k+1){
    rep(i,k*2+1){
            mp[i+j]+=ma[i];
        //cout<<w[i]+j<<" ";
    }}
        //cout<<n<<endl;

    cout<<mp[a]<<endl;
    
    return 0;
}
