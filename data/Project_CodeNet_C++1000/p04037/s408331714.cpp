#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
    for(int i=1;i<=n;++i)
    if(i+1>a[i+1])
    {
        int ans=0;
        for(int j=i+1;a[j]>i-1;++j)ans^=1;
        ans|=(a[i]-i)&1;
        if(ans)printf("First");
        else printf("Second");
        return 0;
    }
}