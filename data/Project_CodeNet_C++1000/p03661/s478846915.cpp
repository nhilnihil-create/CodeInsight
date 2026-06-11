#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>

using namespace std;
using ll = long long;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){ cin >> a[i]; }
	const ll total = accumulate(a.begin(), a.end(), 0ll);
	ll acc = 0, answer = 1000000000000000000ll;
	for(int i = 0; i + 1 < n; ++i){
		acc += a[i];
		const ll x = acc, y = total - acc;
		answer = min(answer, llabs(x - y));
	}
	cout << answer << endl;
	return 0;
}

