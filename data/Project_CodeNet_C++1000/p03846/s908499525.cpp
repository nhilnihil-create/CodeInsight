#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll bigmod(ll a, ll b, ll m)  {
	
	a %= m;
	ll res = 1;
	while(b > 0) {
		
		if(b & 1) {
			res = (res * a) % m;
		}
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}
int main() {
	// your code goes here
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;
	for(auto& x : a) {
		cin >> x;
		mp[x]++;
	}
	
	if(n%2) {
		
		if(mp[0] != 1) {
			cout << 0 << endl;
			return 0;
		}
		
		mp.erase(0);
	}
	
	for(auto x : mp) {
		
		if(x.second  & 1) {
			
			cout << 0 << endl;
			return 0;
		}
	}
	
	cout << bigmod(2, n/2, 1e9+7) << endl;
	
	
	return 0;
}