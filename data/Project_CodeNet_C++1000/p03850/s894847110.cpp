#include<iostream>
#define int long long
using namespace std;
int n,a[200001],b[200001],s[200001],q[200001];
char t[5];
inline int sum(int l,int r){return s[r]-s[l-1];}
signed main()
{
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(i>1)cin>>t;
		cin>>a[i];
		cnt+=b[i]=t[0]=='-';
		s[i]=s[i-1]+a[i];
		q[i]=q[i-1]+(b[i]?-a[i]:a[i]);
	}
	int ans=(cnt<2?q[n]:-(1ll<<40));
	for(int i=n,j=n+1;i;i--)
		if(b[i])
		{
			if(j<=n)ans=max(ans,q[i-1]-sum(i,j-1)+sum(j,n));
			j=i;
		}
	cout<<ans<<endl;
	return 0;
}