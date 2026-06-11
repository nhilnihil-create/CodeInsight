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
	priority_queue<ll> pq1;
	priority_queue<ll, vector<ll> , greater<ll> > pq2;
	ll sum1[n+1],ans1=0;
	for(int i = 0 ;i<2*n; i++)
	{
		pq2.push(a[i]);
		ans1 += a[i];
		if(i==n-1)
			sum1[0] = ans1;
		else if(i>n-1)
		{
			ans1-= pq2.top();
			sum1[i-n+1] = ans1;
			pq2.pop();
		}
	}
	ans1 = 0;
	for(int i = 3*n-1; i>=n; i--)
	{
		pq1.push(a[i]);
		ans1 += a[i];
		if(i==2*n)
			ans = max(ans,sum1[n]-ans1);
		else if(i<2*n)
		{
			ans1 -= pq1.top();
			ans = max(ans,sum1[i-n]-ans1);
			pq1.pop();
		}
	}
	cout<<ans<<endl;
	return 0;
}