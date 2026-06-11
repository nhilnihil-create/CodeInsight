#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const int maxn=101000;
const ll maxx=1e9+10;
ll h,w;
int n;
struct node{
    ll ai,bi;
};
ll ans[10];
node sum[maxn];
map<ll,ll>mp;
map<ll,ll>mp1;

bool cmp(node n1,node n2){
    if(n1.ai==n2.ai) return n1.bi<n2.bi;
    else return n1.ai<n2.ai;
}

void solve(ll x1,ll y11,int x2,int y2){
     ll xx=x1-x2+1,yy=y11-y2+1;
     if(xx+2>h||yy+2>w||xx<1||yy<1) return;
     if(mp[xx*maxx+yy]) return;
     int cnt=0;
     for(int i=1;i<=3;i++){
         for(int j=1;j<=3;j++){
             ll f1=xx+i-1;
             ll f2=yy+j-1;
             if(mp1[f1*maxx+f2]==1) cnt++;
         }
     }
     mp[xx*maxx+yy]=1;
     ans[cnt]++;
}


int main(){
    scanf("%lld%lld%d",&h,&w,&n);
    for(int i=1;i<=n;i++) scanf("%lld%lld",&sum[i].ai,&sum[i].bi);
    for(int i=1;i<=n;i++) mp1[sum[i].ai*maxx+sum[i].bi]=1;
    sort(sum+1,sum+n+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=3;k++){
                solve(sum[i].ai,sum[i].bi,j,k);
            }
        }
    }
    ll tmp=0;
    for(int i=1;i<=9;i++) tmp+=ans[i];
    ans[0]=(h-2)*(w-2)-tmp;
    for(int i=0;i<=9;i++) printf("%lld\n",ans[i]);
    return 0;
}