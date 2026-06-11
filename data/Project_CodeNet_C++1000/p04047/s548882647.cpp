#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=210;
int n;
int a[N];
long long ans=0ll;
int main()
{
    scanf("%d",&n);
    for(int k=1;k<=n*2;k++)
        scanf("%d",&a[k]);
    sort(a+1,a+1+n*2);
    for(int k=1;k<=n*2;k+=2)
        ans+=a[k];
    printf("%lld\n",ans);
    return 0;
}
