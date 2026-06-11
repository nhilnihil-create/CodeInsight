#include<bits/stdc++.h>
#pragma optimizer(O2)
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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005
LL cal(LL u,LL d,LL l){
  //  printf("%d %d %d\n",u,d,l);
    if(l==0)return 0;
    LL res=(u-1)/l*l*2+l+((u-1)%l+1);
    u%=l;
    LL tmpd=l;
    LL tmpl=u;
    LL tmpu=l-u;
    return res+cal(tmpu,tmpd,tmpl);
}
int main(){
    LL n,x;
    scanf("%lld %lld",&n,&x);
    printf("%lld\n",cal(x,n,n-x)+x);
}