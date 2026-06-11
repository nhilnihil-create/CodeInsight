#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,ans=0;
int a[200005],visited[200005];

signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++)  cin>>a[i];
	for (int i=1;i<=n;i++)  visited[a[i]]++;
	
	for (int i=1;i<=200000;i++)  ans=max(ans,visited[i]+visited[i-1]+visited[i+1]);
	cout<<ans<<endl;
	
	return 0;
}