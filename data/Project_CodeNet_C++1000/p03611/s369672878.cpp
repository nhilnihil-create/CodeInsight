#include <stdio.h>
#include <string.h>
const int MAXN=1e5+10;
long long a[MAXN],z[MAXN]={0};
int main()
{
    long long n;
    int i,j;
    int max=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        z[a[i]]++;
        z[a[i]+1]++;
        z[a[i]-1]++;
    }
    for(i=0;i<MAXN;i++)
    {
        if(z[i]>max)max=z[i];
    }
    printf("%d\n",max);
}
