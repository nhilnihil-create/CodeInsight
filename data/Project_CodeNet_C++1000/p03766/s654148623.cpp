#include<bits/stdc++.h>
#define N 1000007
#define P 1000000007
using namespace std;
int f[N];
int inc(int a,int b){a+=b;return a>=P? a-P:a;}
int main()
{
    int n,i,sum=0;scanf("%d",&n);
    if(n==1) return !printf("1");
    f[n]=n,f[n-1]=1ll*n*n%P;
    for(i=n-2;i;--i) sum=inc(sum,f[i+3]),f[i]=inc(inc(inc(f[i+1],1ll*(n-1)*(n-1)%P),sum),i+1);
    return !printf("%d",f[1]);
}
