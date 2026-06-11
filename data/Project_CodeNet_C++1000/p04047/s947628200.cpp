#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define f first
#define s second
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	n *= 2;
	int a[n];
	for(int i =0;i <n ;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	ll ans =0;
	for(int i =0;i<n;i+=2)
		ans +=a[i];
	cout<<ans<<endl;
	return 0;
}