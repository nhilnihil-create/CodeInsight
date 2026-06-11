#include<bits/stdc++.h>
const int dx[]={0,0,-1,1,-1,-1,1,1};
const int dy[]={-1,1,0,0,-1,1,-1,1};
using namespace std;
int n,k,a[5005];
bitset<5005> sum;
bool judge(int x)
{
	if(a[x]>=k)
		return 1;
	sum.reset();
	sum[0]=1;
	for(int i=1;i<=n;i++)
		if(i!=x)
			sum|=sum<<a[i];
	for(int i=k-1;i>=k-a[x];i--)
		if(sum[i])
			return true;
	return false;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=0,r=n+1;
	while(l<r)
	{
		int m=(l+r)>>1;
		if(judge(m))
			r=m;
		else	
			l=m+1;
	}
	cout<<l-1;
	return 0;
}