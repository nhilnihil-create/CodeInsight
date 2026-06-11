#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int n , k;
	cin >> n >> k;
	vector<int> a(n); for(int i = 0; i < n; i++)cin >> a[i];
	if(k > *max_element(a.begin(), a.end())) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	int gc = a[0];
	for(int i = 0; i < n; i++) {
		gc = __gcd(a[i], gc);
	}

	for(int i = 0; i < n; i++) {
		if(a[i] < k)continue;
		if((a[i] - k) % gc == 0) {
			cout << "POSSIBLE" << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;

}