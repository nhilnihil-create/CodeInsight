#include<iostream>
#include<vector>
#include<cmath>
#include<utility>
#include<algorithm>
#include<map>
using namespace std;
typedef long long int ll;
int main(void) {
	int n; cin >> n;
	std::map<ll, ll> mp;
	int a, b, max = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (max < a)max = a;
		mp.emplace(a, b);
	}
	auto iter = mp.find(max);
	cout << iter->first + iter->second << endl;
	return 0;
}