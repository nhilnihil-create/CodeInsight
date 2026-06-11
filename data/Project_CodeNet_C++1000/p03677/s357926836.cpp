#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=100005;
int n,m;
int a[max_n];
ll k[max_n],b[max_n];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    function<void(int,int,int,int)> add=[&](int l,int r,int kx,int bx){
        k[l]+=kx,k[r+1]-=kx,b[l]+=bx,b[r+1]-=bx;
    };
    function<void(int,int)> work=[&](int s,int t){
        if(s<t){
            add(1,s,0,t-s);
            add(s+1,t,-1,t+1);
            add(t+1,m,0,t-s);
        }
        else{
            add(1,t,-1,t+1);
            add(t+1,s,0,t+m-s);
            add(s+1,m,-1,t+m+1);
        }
    };
    for(int i=1;i<n;i++){
        work(a[i],a[i+1]);
    }
    for(int i=1;i<=m;i++)k[i]+=k[i-1],b[i]+=b[i-1];
    ll ans=1e18;
    for(int i=1;i<=m;i++)ans=min(ans,k[i]*i+b[i]);
    printf("%lld\n",ans);
    return 0;
}