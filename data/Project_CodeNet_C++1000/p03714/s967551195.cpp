#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<ll> a(3*n);
	ll ans = -1e18;
	for(int i = 0; i<3*n; i++)
		cin>>a[i];
	multiset<ll,greater<ll> > pq1;
	multiset<ll> pq2;
	ll sum1[n+1],sum2[n+1],sum11=0,sum22=0;
	for(int i = 0; i<n; i++)
	{
		sum11 +=a[i];
		pq1.insert(a[i]);
	}
	sum1[0]=sum11;
	for(int i = n; i<2*n;i++)
	{
		pq1.insert(a[i]);
		int y = *(--pq1.end());
		pq1.erase(--pq1.end());
		sum11 += a[i];
		sum11 -= y;
		sum1[i-n+1] = sum11;
	}
	for(int i = 3*n-1; i>=2*n; i--)
	{
		sum22 += a[i];
		pq2.insert(a[i]);
	}
	sum2[n] = sum22;
	for(int i = 2*n-1; i>=n; i--)
	{
		pq2.insert(a[i]);
		int y = *(--pq2.end());
		pq2.erase(--pq2.end());
		sum22 += a[i];
		sum22 -= y;
		sum2[i-n] = sum22;
	}
	for(int i = 0; i<n+1; i++)
		ans = max(ans,sum1[i]-sum2[i]);
	cout<<ans<<endl;
	return 0;
}