#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10, N = 5e2 + 10;
int a[N], n;
int mark[MAXN];
vector<pair<int, int> > v;
deque<int> rm;
bool isval() {
	int ls = 0, mx = n * (n - 1) / 2;
	for (auto p : v) {
		int plc = p.first, num = p.second;
		ls += num;
		if (!(plc >= ls && plc <= mx)) 
			return false;
		mx += n - num;
		ls++;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio (false), cin.tie(0), cout.tie(0);
	memset(mark, -1, sizeof(mark));
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		if (mark[a[i]] != -1) {
			cout << "No\n";
			return 0;
		}
		mark[a[i]] = i;
		v.push_back({a[i], i});
	}
	sort(v.begin(), v.end());
	if (!isval()) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	for (auto p : v) {
		int num = p.second;
		for (int i = 0; i < num; i++)
			rm.push_back(num);
	}
	for (int i = 0; i < n * n; i++) {
		if (mark[i] != -1) {
			int add = n - mark[i] - 1;
			for (int j = 0; j < add; j++)
				rm.push_back(mark[i]);
		}
		else {
			mark[i] = rm[0];
			rm.pop_front();
		}
	}
	for (int i = 0; i < n * n; i++)
		cout << mark[i] + 1 << " ";
	return 0;
}
