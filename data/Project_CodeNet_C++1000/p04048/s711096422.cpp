#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll func(ll a, ll b) {
	ll temp;
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main()
{
    ll n, x;
    cin>>n>>x;
    ll t = func(n, x);
    n /= t;
    x /= t;
    ll ans = (n - 1)*3 * t;
    cout<<ans<<endl;
    return 0;
}
