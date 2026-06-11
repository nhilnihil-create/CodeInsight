#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
ll n,l,t,x,w,ans[100005];
int main(){
    scanf("%lld%lld%lld",&n,&l,&t);
    ll p=1;
    for (int i=1; i<=n; i++)
	{
        scanf("%lld%lld",&x,&w);
        if (w==1)
		{
            ans[i]=(x+t)%l;
            p+=(x+t)/l;
        }
		else
		{
            ans[i]=(x-t)%l;
            p+=(x-t)/l;
            if(ans[i]<0)ans[i]+=l,p--;
        }
    }
    sort(ans+1,ans+n+1);
    p=(p%n+n)%n;
    if (p==0) p=n;
    for (int i=p; i<=n; i++)
        printf("%lld\n",ans[i]);
    for (int i=1; i<=p-1; i++)
        printf("%lld\n",ans[i]);
    return 0;
}