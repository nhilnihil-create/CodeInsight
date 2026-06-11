#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	vector <int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	ll r = v[n - 1];
	ll l = 0;
	while(r - l > 1) {
		ll m = (l + r)/2;
		ll sum = 0;
		for(int i = 0; i < n; i++) {
			if(v[i] > b * m) {
				if((v[i] - b*m) % (a-b)) sum += (v[i] - b*m) / (a-b) + 1;
				else sum += (v[i] - b*m) / (a-b);
			}
		}
		if(sum > m) l = m;
		else r = m;
	}
	cout << r << "\n";
	return 0;
}
