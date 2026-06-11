#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int arr[N];
int dp[N][22];
int n,l,q;

int get(int a,int x)
{
	for(int i=21;i>=0;i--)
	{
		if(x&(1<<i))
			a=dp[a][i];
	}
	return a;
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cin >> l >> q;
	int r=0;
	for(int i=0;i<n;i++)
	{
		if(r<i) r=i;
		while(r+1<n&&arr[r+1]-arr[i]<=l) r++;
		dp[i][0]=r;
	}
	for(int j=1;j<22;j++)
		for(int i=0;i<n;i++)
			dp[i][j]=dp[dp[i][j-1]][j-1];
	while(q--)
	{
		int a,b;
		cin >> a >> b;
		a--; b--;
		if(a>b) swap(a,b);
		int st=1,en=n,ans=n;
		while(st<=en)
		{
			int mid=(st+en)/2;
			//cout << a << " " << mid << " " << get(a,mid) << endl;
			if(get(a,mid)>=b)
			{
				ans=mid; en=mid-1;
			}
			else
				st=mid+1;
		}
		printf("%d\n",ans);
	}
}