#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	vector<ll> p;
	int count = 1;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1])
			count++;
		else {
			if (count >= 4) {
				p.push_back(a[i]);
				p.push_back(a[i]);
			}
			else if (count >= 2)
				p.push_back(a[i]);
			count = 1;
		}
	}
	if (count >= 4) {
		p.push_back(a[n - 1]);
		p.push_back(a[n - 1]);
	}
	else if (count >= 2)
		p.push_back(a[n - 1]);
	if (p.size() < 2) {
		cout << 0 << endl;
		return 0;
	}
	sort(p.rbegin(), p.rend());
	cout << p[0] * p[1] << endl;
	return 0;
}
