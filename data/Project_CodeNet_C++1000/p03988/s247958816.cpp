#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=105;

int n,t[N];

int main()
{
    scanf("%d",&n);int mx=0;
    for (int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        t[x]++;mx=max(mx,x);
    }
    if (!(mx&1)&&t[mx/2]!=1||(mx&1)&&t[(mx+1)/2]>2) {puts("Impossible");return 0;}
    for (int i=(mx+1)/2+1;i<=mx;i++) if (t[i]<2) {puts("Impossible");return 0;}
    for (int i=1;i<(mx+1)/2;i++) if (t[i]) {puts("Impossible");return 0;}
    puts("Possible");
    return 0;
}