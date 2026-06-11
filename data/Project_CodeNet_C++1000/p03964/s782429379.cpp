#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t; cin >> t;
	
	ll prev1 = 1;
	ll prev2 = 1;
	
	while(t--) {
		
		ll a,b; cin >> a >> b;
		
		ll na = prev1 / a + (prev1 % a != 0);
		ll nb = prev2 / b + (prev2 % b != 0);
		
		prev1 = a*max(na,nb);
		prev2 = b*max(na,nb);
	}
	
	cout << prev1 + prev2 << '\n';
	
	return 0;
}