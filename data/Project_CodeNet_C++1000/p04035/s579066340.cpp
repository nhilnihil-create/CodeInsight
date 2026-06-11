#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5;
int n,L,w[N];
int main()
{
    scanf("%d%d",&n,&L);
    for(int i=1;i<=n;i++)scanf("%d",w+i);
    int pd=0;
    for(int i=1;i<n;i++)if(w[i]+w[i+1]>=L){pd=i;break;}
    if(!pd){puts("Impossible");return 0;}
    puts("Possible");
    for(int i=1;i<pd;i++)printf("%d\n",i);
    for(int i=n-1;i>pd;i--)printf("%d\n",i);
    printf("%d\n",pd);
}