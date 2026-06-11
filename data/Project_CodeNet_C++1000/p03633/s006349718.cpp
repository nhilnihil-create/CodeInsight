#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	ll  arr[n];
	cin >> arr[0];
	__int128  lcm = arr[0];
	for (int i = 1; i < n; i++) {
		cin >> arr[i];
		lcm = (lcm * arr[i]) / __gcd((__int128)arr[i], lcm);
	}

	cout << (ll)lcm;

	return 0;

}
