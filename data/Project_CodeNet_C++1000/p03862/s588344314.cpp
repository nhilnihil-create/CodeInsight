#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define lld long long int
#define ld long double
#define mpi 3.14159265358979323846
#define mod 1000000007
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x;
	cin >> n >> x;
	int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(b[i]>x)
		{
			b[i] = x;
		}
	}
	for(int i=0;i<n-1;i++)
	{
		if(b[i]+b[i+1]>x)
		{
			b[i+1] = x-b[i];
		}
	}
	lld ans = 0;
	for(int i=0;i<n;i++)
	{
		ans+=(lld)abs(b[i]-a[i]);
	}
	cout << ans << "\n";
	return 0;
}
