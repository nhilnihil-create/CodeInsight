#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5e5;
int n,w[N],cnt[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",w+i);
    sort(w+1,w+n+1);
    if(w[n]!=w[n-1]){puts("Impossible");return 0;}
    if(n==2){puts("Possible");return 0;}
    if(w[1]<((w[n]+1)>>1)){puts("Impossible");return 0;}
    for(int i=1;i<=n;i++)cnt[w[i]]++;
    for(int i=(w[n]+3)>>1;i<=w[n];i++)if(cnt[i]<2){puts("Impossible");return 0;}
    if(cnt[(w[n]+1)>>1]>(w[n]&1)+1){puts("Impossible");return 0;}
    puts("Possible");
    return 0;
}