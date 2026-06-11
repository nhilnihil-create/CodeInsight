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
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i = 0;i<n; i++)
		cin>>a[i];
	sort(a,a+n,greater<int>());
	ll ans = 0;
	for(int i= 0; i<k;i++)
		ans += a[i];
	cout<<ans<<endl;
	return 0;
}