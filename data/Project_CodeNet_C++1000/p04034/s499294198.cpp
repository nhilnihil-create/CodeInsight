#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 1LL<<60
#define pi 3.14159265358979323846
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

//redが行きうる全ての箱の個数

int main(){
    ll n,m;cin>>n>>m;
    vector<bool> possible(100010,0);
    vector<ll> how_many(n,1);//箱にあるボールの個数
    possible[0]=true;

    for(ll i=0;i<m;i++){
        ll x,y;cin>>x>>y;
        x--;y--;
        if(possible[x]==true && how_many[x]>0){possible[y]=true;}
        if(how_many[x]>0){how_many[x]--;how_many[y]++;}
        if(how_many[x]==0){possible[x]=false;}
    }

    ll ans=0;
    for(ll i=0;i<n;i++){
        if(possible[i] && how_many[i]>0){ans++;}
    }

    cout<<ans<<endl;
    return 0;
}