#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll n,m,k;
    cin>>n>>m>>k;
    bool f[n*m];
    rep(1,i,n*m)f[i]=false;
    ll tmp1=0,tmp2=0;
    rep(0,i,n+1){
        if(i!=0)tmp1+=m;
        tmp2=tmp1;
        rep(0,j,m+1){
            if(j!=0)tmp2+=(n-2*i);
            //cout<<j<<" "<<i<<" "<<tmp2<<endl;
            f[tmp2]=true;
        }
    }
    if(f[k])cout<<"Yes";
    else cout<<"No";
}