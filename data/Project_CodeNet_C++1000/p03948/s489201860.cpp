#include<bits/stdc++.h>
#include<string>
#define LL long long
#define INF 0x3f3f3f3f
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int N=2e5+100;
using namespace std;
LL a[N];
LL tmp[N],tot;
LL maxs[N];
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		tot=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=n;i>=1;i--)maxs[i]=max(maxs[i+1],a[i]);
		for(int i=1;i<n;i++)
			tmp[++tot]=maxs[i+1]-a[i];
		sort(tmp+1,tmp+1+tot);
		reverse(tmp+1,tmp+1+tot);
		LL ans=0;
		for(int i=1;i<=tot;i++)
			if(tmp[i]==tmp[1])ans++;
		cout<<ans<<endl;
	}
	return 0;
} 