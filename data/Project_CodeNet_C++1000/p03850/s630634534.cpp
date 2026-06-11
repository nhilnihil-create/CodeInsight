#include<bits/stdc++.h>
#define to edge[i].v
#define mp make_pair
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
#define N 100010
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
int a[N]; ll pre[N],suf[N]; char c[N];
int main()
{	ios::sync_with_stdio(false);
	int n; ll ans=0; cin>>n>>a[1]; pre[1]=a[1];
	for(rint i=2;i<=n;i++) cin>>c[i]>>a[i];
	for(rint i=2;i<=n;i++) pre[i]=(c[i]=='-')?pre[i-1]-a[i]:pre[i-1]+a[i];
	for(rint i=n;i>=1;i--) suf[i]=suf[i+1]+a[i];
	for(rint i=1,j;i<=n;i++)
	if(c[i]=='-')
	{	ll sum=a[i];
		for(j=i+1;j<=n&&c[j]=='+';j++) sum+=a[j];
		ans=max(ans,pre[i-1]+suf[j]-sum);
	}
	cout<<max(ans,pre[n]);
	return 0;
}
