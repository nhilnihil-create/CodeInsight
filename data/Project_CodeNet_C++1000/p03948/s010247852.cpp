#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000+10;
int n,T,a[MAXN],mxa,mxv,ans;
int main()
{
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=n;i>=1;--i)
	{
		if(mxa-a[i]>mxv)mxv=mxa-a[i],ans=1;
		else if(mxa-a[i]==mxv)ans++;
		mxa=max(mxa,a[i]);
	}
	printf("%d\n",ans);
	return 0;
}