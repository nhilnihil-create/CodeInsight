#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
int main()
{	
	ll n, k;
	cin >> n >> k;
	ll ans = k;
	while(--n) {
	 	ans *= (k-1);
	}
	cout << ans << endl;
	return 0;
}