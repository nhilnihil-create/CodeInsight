#include<bits/stdc++.h>
#define rg register
#define Inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
inline ll min(ll x,ll y){return x<y?x:y;}
inline ll max(ll x,ll y){return x>y?x:y;}
const int Maxn=2e5+5;
inline int read()
{
	rg int res=0,sign=1;
	rg char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
			sign=-1;
		ch=getchar();
	}
	do
	{
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}while(isdigit(ch));
	return res*sign;
}
int n;
int a[Maxn],Max,Min;
bool b[Maxn];
bool check(int x)
{
	for(int i=1;i<=2*n-1;i++)
		b[i]=a[i]>=x;
	if(b[n]==b[n+1]) return b[n+1];
	if(b[n]==b[n-1]) return b[n-1];
	int l=0,r=0;
	for(int i=n-1;i>=1;i--)
		if(b[i]!=b[i+1])
			l++;
		else
			break;
	for(int i=n+1;i<2*n;i++)
		if(b[i]!=b[i-1])
			r++;
		else
			break;
	return l<r?b[n-l]:b[n+r];
}
int Search(int l,int r)
{
	if(l==r)
		return l;
	int mid=(l+r>>1)+1;
	if(check(mid))
		return Search(mid,r);
	return Search(l,mid-1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=2*n-1;i++)
		a[i]=read();
	Min=Max=a[1];
	for(int i=2;i<=2*n-1;i++)
	{
		Min=min(Min,a[i]);
		Max=max(Max,a[i]);
	}
	cout<<Search(Min,Max)<<endl;
	return 0;
}
