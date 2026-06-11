#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n,m;
	cin >> n >> m;
	vector<int> e[n];
	set<int> v;
	int start = 0,end = 0;
	for (int i = 0;i < m;i++) {
		int x,y;
		cin >> x >> y;
		e[x-1].push_back(y-1);
		e[y-1].push_back(x-1);
	}
	int ans[3 * n];
	for (int i = 0;i < 3 * n;i++) {
		ans[i] = -1;
	}
	ans[n] = 1;
	int spos = n-1,epos = n+1;
	v.insert(0);
	bool ok = false;
	while (!ok) {
		ok = true;
		for (int i = 0;i < e[start].size();i++) {
			if (v.find(e[start][i]) == v.end()) {
				ok = false;
				start = e[start][i];
				v.insert(start);
				ans[spos] = start+1;
				spos--;
				break;
			}
		}
		for (int i = 0;i < e[end].size();i++) {
			if (v.find(e[end][i]) == v.end()) {
				ok = false;
				end = e[end][i];
				v.insert(end);
				ans[epos] = end+1;
				epos++;
				break;
			}
		}
	}
	cout << v.size() << endl;
	for (int i = 0;i < v.size();i++) {
		cout << ans[i+spos+1];
		if (i != n-1) cout << " ";
	}
	cout << endl;
}