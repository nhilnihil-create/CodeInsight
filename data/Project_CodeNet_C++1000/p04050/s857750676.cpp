#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> e, o;
vector<int> v, ans;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		if (x & 1) o.push_back(x);
		else e.push_back(x);
	}
	if (o.size() >= 3) {
		puts("Impossible");
		return 0;
	}
	if (o.size() == 0) {
		v = e;
	} else if (o.size() == 1) {
		v.push_back(o[0]);
		v.insert(v.end(), e.begin(), e.end());
	} else {
		v.push_back(o[0]);
		v.insert(v.end(), e.begin(), e.end());
		v.push_back(o[1]);
	}
	for (int i = 0; i < (int)v.size(); i++)
		printf("%d ", v[i]);
	puts("");
	if (v.size() == 1) {
		if (v[0] - 1) ans.push_back(v[0] - 1);
		ans.push_back(1);
	} else {
		if (v[0] - 1) ans.push_back(v[0] - 1);
		ans.push_back(2);
		for (int i = 1; i < (int)v.size() - 1; i++)
			ans.push_back(v[i]);
		if (v.back() - 1) ans.push_back(v.back() - 1);
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}