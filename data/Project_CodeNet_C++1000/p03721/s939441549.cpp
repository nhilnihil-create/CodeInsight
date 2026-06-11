#include<bits/stdc++.h>
using namespace std;

int main() {
	map<int, long long>mp;
	int n; cin >> n;
	long long k; cin >> k;
	while (n--) {
		int num, cop; cin >> num >> cop;
		mp[num] += cop;
	}
	for (auto it : mp) {
		if (k <= it.second) return cout << it.first, 0;
		k -= it.second;
	}
	return 0;
}