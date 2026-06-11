#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int MAX=2e5+5;
const int MOD=1000000000;
const long long int Min=(2e5)*(1e9)+5;
long long int  a[MAX];
long long int sum[MAX];

int main()
{
    ios::sync_with_stdio(false);
    int N;
   scanf("%d",&N);
    long long int sum2=0;
    for(int i=1;i<=N;i++)
    {
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
        sum2+=a[i];
    }
    long long int min=Min;
    for(int i=1;i<N;i++)
    {
           if(min>fabs(2*sum[i]-sum2))
           min=fabs(2*sum[i]-sum2);
    }
    printf("%d\n",min);

    return 0;
}