#include<bits/stdc++.h>
using namespace std;
int a[210],b[210],la,lb,i=100;
int main()
{
    long long n;
    scanf("%lld",&n);
    n++;
    while(n>1)
    {
        if(n&1)n--,a[++la]=i--;
        else n>>=1,b[++lb]=i--;
    }
    printf("%d\n",(la+lb)*2);
    for(int j=1;j<=la;j++)
        printf("%d ",a[j]-i);
    for(int j=lb;j>=1;j--)
        printf("%d ",b[j]-i);
    for(int j=100-la-lb+1;j<100;j++)
        printf("%d ",j-i);
    printf("%d\n",100-i);
    return 0;
}