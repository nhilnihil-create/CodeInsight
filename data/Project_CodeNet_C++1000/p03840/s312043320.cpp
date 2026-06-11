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
#define MXN 200005
int main(){
    int a[7];
    for(int i = 0;i<7;i++)
    scanf("%d",&a[i]);
    LL ans=0;
    ans+=a[0]/2*2;
    ans+=a[1];
    ans+=a[3]/2*2;
    ans+=a[4]/2*2;
    if((a[0]&1)&&(a[3]&1)&&(a[4]&1))ans+=3;
    if((a[0]&1)+(a[3]&1)+(a[4]&1)==2&&a[0]&&a[1]&&a[2])ans++;
    printf("%lld\n",ans);
}
/*
1441152
*/