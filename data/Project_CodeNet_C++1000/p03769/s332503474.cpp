#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector

int main(void)
{
	ll n;
	cin >> n;
	
	int keta = 0;
	while(1) {
		if (n < (1LL << (keta + 1)) - 1) break;
		keta++;
	}

	vec<int> p(keta);
	rep(i, keta) p[i] = i + 1;
	int use = keta;
	n -= (1LL << keta) - 1;

	for (int i = keta - 1; i >= 0; i--) {
		if (n < (1LL << i)) continue;
		use++;
		p.insert(p.begin() + i, use);
		n -= (1LL << i);
	}
	cout << 2 * p.size() << endl;
	cout << p[0];
	rep(i, p.size() - 1) cout << " " << p[i + 1];
	rep(i, p.size()) cout << " " << i + 1;
	cout << endl;
	return 0;
}