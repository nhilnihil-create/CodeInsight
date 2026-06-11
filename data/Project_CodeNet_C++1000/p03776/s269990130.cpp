#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll n,a,b;cin>>n>>a>>b;
    vector<vector<ll> >pas(52,vector<ll>(52));
    pas[0][0]=1;
    rep(i,51){
        rep(j,51){
            if(i+j>50)continue;
            pas[i+1][j]+=pas[i][j];
            pas[i][j+1]+=pas[i][j];
        }
    }
    vector<ll>v(n);
    rep(i,n){
        cin>>v[i];
    }
    sort(all(v));
    reverse(all(v));
    vector<ll>rui(n+1);
    ll ma=rui[a];
    ll idx=a;
    rep(i,n){
        rui[i+1]=v[i]+rui[i];
        if(i+1>=a&&i+1<=b){
            if(ma*(i+1)<idx*rui[i+1]){
                ma=rui[i+1];
                idx=i+1;
            }
        }
    }
    ll ans=0;
    REP(i,a,b+1){
        if(ma*i==idx*rui[i]){
            ll k=i;
            ll cnt1=0,cnt2=0;
            rep(j,n){
                if(v[k-1]<v[j])cnt1++;
                if(v[j]==v[k-1])cnt2++;
            }
            ans+=pas[cnt2-(k-cnt1)][k-cnt1];
        }
    }
    cout<<fixed<<setprecision(6)<<(double)ma/(double)idx<<endl;
    cout<<ans<<endl;
}