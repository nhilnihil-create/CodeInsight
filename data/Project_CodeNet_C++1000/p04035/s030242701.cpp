#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
int main(){
    int n,L;
    scanf("%d %d",&n,&L);
    int a[100005];
    LL tot=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        tot+=a[i];
    }
    for(int i = 1;i<n;i++){
        if(a[i]+a[i+1]>=L){
            printf("Possible\n");
            for(int j=1;j<i;j++)
            printf("%d\n",j);
            for(int j=n-1;j>=i;j--)
            printf("%d\n",j);
            return 0;
        }
    }
    printf("Impossible\n");
}