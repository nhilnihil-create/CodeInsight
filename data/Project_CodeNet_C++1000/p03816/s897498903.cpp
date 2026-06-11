#include<bits/stdc++.h>
#define s(a,l,r) sort(a+l,a+r+1)
#define f(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
int a[110000];
int main()
{
	int n,ans=0;
    scanf("%d",&n);
    f(i,1,n) scanf("%d",&a[i]);
    s(a,1,n);
    f(i,1,n) if(a[i]==a[i-1]) ans++;
    ans=(ans+1)/2*2;
    printf("%d\n",n-ans);
    return 0;
}