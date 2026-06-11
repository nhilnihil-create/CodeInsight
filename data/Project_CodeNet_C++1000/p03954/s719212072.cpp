#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 200005;
int a[MAXN],t[MAXN],n;
inline bool check(int limit)
{
	for(int i=1;i<=n*2-1;++i)
		t[i]=(a[i]>=limit);
	int l=-1,r=-1,lpos=-0x3f3f3f3f,rpos=0x3f3f3f3f;
	for(int i=n+1;i<=n*2-1;++i)
		if(t[i]==t[i-1]){r=t[i],rpos=i-1;break;}
	for(int i=n-1;i>0;--i)
		if(t[i]==t[i+1]){l=t[i],lpos=i+1;break;}
	if(l==-1 && r==-1)
		if(n&1)return t[n];
		else return t[n]^1;
	else return (rpos-n>n-lpos?l:r);
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*2-1;++i)
		scanf("%d",a+i);
	int l=1,r=n*2-1,mid,ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
