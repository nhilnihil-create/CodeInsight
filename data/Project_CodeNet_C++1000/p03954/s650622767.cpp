#include<bits/stdc++.h>
using namespace std;
const int N=300010;
int a[N],n,b[N],m;//2*n+1
int c[N];
int pd(int x)
{
	for(int i=1;i<=m;i++)
	if(a[i]<=x)c[i]=0;else c[i]=1;
	if(n==1)return c[n];
	if(c[n]==c[n+1]||c[n]==c[n-1])return c[n];
	//cout<<x<<" ";for(int i=1;i<=m;i++)cout<<c[i];cout<<endl;
	int l,r;
	for(l=n;l;l--)if(c[l]==c[l-1])break;
	for(r=n;r<=m;r++)if(c[r]==c[r+1])break;
	if(n<=min(n-l+1,r-n+1))
	{
		if(n%2)return c[n];else return c[n]^1;
	}//cout<<l<<" "<<r<<endl;
	if(n-l+1<r-n+1)return c[l];else return c[r];
}
int main()
{
	//freopen("triangle.in","r",stdin);
	//freopen("triangle.out","w",stdout);
	scanf("%d",&n);m=2*n-1;
	for(int i=1;i<=m;i++)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+m+1);int ou=unique(b+1,b+m+1)-b-1;
	for(int i=1;i<=m;i++)a[i]=lower_bound(b+1,b+ou+1,a[i])-b;
	int l=1,r=m+1,mid;
	while(l<r)
	{
		mid=(l+r>>1);
		if(pd(mid))l=mid+1;
		else r=mid;
	}
	printf("%d",b[r]);
}