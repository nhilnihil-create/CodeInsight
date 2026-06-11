// lcmとかはg++ -std=c++17 default.cppみたいなかんじで
//vector<vector<ll>> piyo(tate,vector<ll> (yoko));

#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1000000000
#define ll long long
#define ln cout<<endl;
#define Yes cout<<"Yes"<<endl;
#define No cout<<"No"<<endl;
#define double long double
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str,str2;
    ll x;
    cin>>n>>x;
    vector<ll> v(n);
    rep(i,n) cin>>v[i];
    if(v[0]>x){
        sum=v[0]-x;
        v[0]=x;
    }
    for(ll i=1;i<n;i++){
        if(v[i]+v[i-1]>x){
        sum+=v[i-1]+v[i]-x;
        v[i]=x-v[i-1];
        }
    }
    cout<<sum<<endl;

    return 0;
}
