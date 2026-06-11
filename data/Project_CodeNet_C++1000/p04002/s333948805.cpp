#include<bits/stdc++.h>
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define pl(x) printf("%lld",x)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define re register
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define per(i,n,m) for(int i=m;i>=n;i--)
#define rrep(i,m,n) for(register int i=m;i<=n;i++)
#define rper(i,n,m) for(register int i=m;i>=n;i--)
#define ull unsigned  long long
using namespace std;
const int INF =1e9+10;
const int N = 5e6 + 10;
ll h,w,node[N],n,cnt,zero,ans[20];
signed main(){
    scanf("%lld%lld%lld",&h,&w,&n);
    zero=(h-2)*(w-2);
    rep(i,1,n){
        ll a,b;
        scanf("%lld%lld",&a,&b);
        for (int i=-2;i<=0;i++){
            for (int j=-2;j<=0;j++){
                if(a+i>=1 && a+i <=h-2 && b+j>=1 &&b+j <=w-2){
                    node[cnt++]=INF*(a+i)+(b+j);
                }
            }
        }
    }
    sort(node,node+cnt);
    for (int i=0,tmp=1;i<cnt;i++){
        if(node[i]==node[i+1]) tmp++;
        else {
            ans[tmp]++;
            zero--;
            tmp = 1;
        }
    }
    pl(zero);
    puts("");
    rep(i,1,9)printf("%lld\n",ans[i]);
    return 0;
}
