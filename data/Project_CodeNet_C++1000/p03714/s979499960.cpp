#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 3e5+10;
const int mod = 1e9 + 7;
int n;
int ans = LONG_MIN;
int a[N],left_sum[N],right_sum[N];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int,vector<int>,greater<int>> pq;
	priority_queue<int> pq2;
	
	cin >> n;
	
	for(int i=1;i<=3*n;++i)
		cin >> a[i];
	for(int i=1;i<=n;++i)
	{
		left_sum[n] += a[i];
		pq.push(a[i]);
	}
	
	for(int i=n+1;i<=2*n;++i)
	{
		if(a[i] > pq.top())
		{
			left_sum[i] = (a[i] - pq.top() + left_sum[i-1]);
			pq.pop();
			pq.push(a[i]);
		}
		else
		{
			left_sum[i] = left_sum[i-1];
		}
	}
	
	for(int i=2*n+1;i<=3*n;++i)
	{
		right_sum[2*n+1] += a[i];
		pq2.push(a[i]);
	}
	
	for(int i=2*n;i>=n+1;--i)
	{
		
		if(a[i] < pq2.top())
		{ 
			right_sum[i] = (a[i] - pq2.top() + right_sum[i+1]);
			pq2.pop();
			pq2.push(a[i]);
		}
		else
		{
			right_sum[i] = right_sum[i+1];
		}
	}
	
	for(int i=n;i<=2*n;++i)
	{
		//~ cout << left_sum[i] << " " << right_sum[i+1] << '\n';
		ans = max(ans,left_sum[i]-right_sum[i+1]);
	}
	cout << ans;
}

