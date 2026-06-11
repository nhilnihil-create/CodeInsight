#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[1000005];
int n, ans;
int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++) 
		cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < n; i ++) 
	{
		a[i] += a[i - 1];
		ans ++;
		if(a[i] * 2 < a[i+1])
			ans=0;
	}
	cout << ans << endl;
	return 0;
}