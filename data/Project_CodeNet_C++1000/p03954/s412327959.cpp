#include<bits/stdc++.h>
using namespace std;
int a[200001];
int s[200001];
int n;
inline bool check(int x)
{
	int l=n-1,r=n+1;
	for(register int i=1;i<=(n<<1)-1;++i)
	  s[i]=(a[i]>=x);
	while(l>=1)
	  {
	   	if(s[l]==s[l+1]) return s[l];
	   	if(s[r]==s[r-1]) return s[r];
	   	--l;++r;
	  }
	return s[1];
}
int main()
{
	scanf("%d",&n);
	for(register int i=1;i<=(n<<1)-1;++i) scanf("%d",&a[i]);
	int l=1,r=1e8,ans=0;
	while(l<r)
	  {
	  	int mid=(l+r)>>1;
	  	if(check(mid)) l=mid+1,ans=mid;
	  	else r=mid;
	  }
	cout<<ans;
    return 0;
}