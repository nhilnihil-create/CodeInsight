#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define GG return printf("Impossible\n"),0
int a[N],num[N];
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),num[a[i]]++;
    sort(a+1,a+n+1);
    if(a[n]!=a[n-1])GG;
    if(a[1]!=(a[n]+1)/2)GG;
    for(int i=a[1]+1;i<a[n];i++)if(num[i]<=1)GG;
    if(!(a[n]&1)){if(num[a[1]]>=2)GG;}
    else {if(num[a[1]]>=3)GG;}
    printf("Possible\n");
}
