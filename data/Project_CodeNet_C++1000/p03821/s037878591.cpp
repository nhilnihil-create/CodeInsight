#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int32_t main()
{
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=n-1;i>=0;i--)cin>>a[i]>>b[i];
	int water=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int cur=water+a[i];
		int nxt=(cur+b[i]-1)/b[i];
		nxt*=b[i];
		int diff=nxt-cur;
		water+=diff;
		ans+=diff;
	}
	cout<<ans;
}
