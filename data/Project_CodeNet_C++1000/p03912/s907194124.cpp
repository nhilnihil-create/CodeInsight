#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

ll n,m,x,X[100001],modx[100000],num_x[100000],ans;

int main(){
    cin>>n>>m;
    rep(i,n){
        cin>>x;
        X[x]++;
        modx[x%m]++;
    }
    rep(i,100001)num_x[i%m]+=(X[i]/2)*2;
    
    rep(i,m){
        ll j=(m-i)%m;
        ll mn=min(modx[i],modx[j]);
        if(i==j)mn/=2;
        ans+=mn;
        modx[i]-=mn;
        modx[j]-=mn;
        ans+=min(modx[i],num_x[i])/2;
    }
    cout<<ans<<endl;
}