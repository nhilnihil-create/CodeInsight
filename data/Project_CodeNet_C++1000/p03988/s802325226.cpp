#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n, m;
int a[N];
multiset<int> Set;

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int mx = a[n];
	if (a[n - 1] != mx) return 0 * puts("Impossible");
	for (int i = 1; i <= n - 2; ++i) {
		Set.insert(a[i]);
	}
	int mi = N;
	for (int i = 2; i <= mx; ++i) {
		int tmp = max(i - 1, mx - i + 1);
		mi = min(mi, tmp);
		set<int>::iterator it;
		it = Set.find(tmp);
		if (it == Set.end()) return 0 * puts("Impossible");
		Set.erase(it);
	}
	if (Set.size() == 0) return 0 * puts("Possible");
	int x = *Set.begin();
	int y = *Set.rbegin();
	if (x < mi + 1) return 0 * puts("Impossible");
	if (y > mx) return 0 * puts("Impossible");
	return 0 * puts("Possible");
}
