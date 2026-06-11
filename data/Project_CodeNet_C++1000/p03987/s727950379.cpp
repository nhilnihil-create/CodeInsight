#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
#define MXN 200005
/*
4+4*2+3+4
*/
int main(){
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    vector<pii> stk;
    int l[200005];
    stk.pb(mp(0,0));
    for(int i = 1;i<=n;i++){
        while(stk.back().x>a[i])stk.pop_back();
        l[i]=stk.back().y;
        stk.pb(mp(a[i],i));
    }
    int r[200005];
    stk.clear();
    stk.pb(mp(0,n+1));
    for(int i = n;i>=1;i--){
        while(stk.back().x>a[i])stk.pop_back();
        r[i]=stk.back().y;
        stk.pb(mp(a[i],i));
    }
    LL ans=0;
    for(int i = 1;i<=n;i++){
        ans+=(LL)a[i]*(r[i]-i)*(i-l[i]);
    }
    printf("%lld\n",ans);
}
