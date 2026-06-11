/*======================
 * Author : ylsoi
 * Problem : AGC02E
 * Algorithm : SG
 * Time : 2018.6.2
 * ===================*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<climits>
using namespace std;
void File(){
    freopen("AGC02E.in","r",stdin);
    freopen("AGC02E.out","w",stdout);
}
template<typename T>bool chkmax(T &_,T __){return _<__ ? (_=__,1) : 0;}
template<typename T>bool chkmin(T &_,T __){return _>__ ? (_=__,1) : 0;}
#define REP(i,a,b) for(register int i=a;i<=b;++i)
#define DREP(i,a,b) for(register int i=a;i>=b;--i)
#define MREP(i,x) for(register int i=beg[x];i;i=E[i].last)
#define mem(a) memset(a,0,sizeof(a))
#define inf INT_MAX
const int maxn=1e5+10;
int n,a[maxn],SG[1010][1010];
bool cmp(int _,int __){return _>__;}
bool judge(int x,int y){return x<=n && y<=a[x];}    
int main(){
    scanf("%d",&n);
    REP(i,1,n)scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    int px=1,py=1,step1=0,step2=0;
    while(judge(px+1,py+1))++px,++py;
    while(judge(px+step1,py))++step1;
    while(judge(px,py+step2))++step2;
    if(step1%2==0 || step2%2==0)puts("First");
    else puts("Second");
    return 0;
}
