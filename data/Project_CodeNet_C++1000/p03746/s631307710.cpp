#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector <int> ad[N];
int n, m;
bool mrk[N];
deque <int> d;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		ad[x].push_back(y);
		ad[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (ad[i].size() > 0) {
			d.push_front(i);
			d.push_back(ad[i][0]);
			mrk[i] = mrk[ad[i][0]] = 1;
			break;
		}	
	}	
	bool s = 1;
	while (s) {
		s = 0;
		int v = d.front();
		for (auto u: ad[v]) {
			if (!mrk[u]) {
				s = 1;
				d.push_front(u);
				mrk[u] = 1;
				break;
			}
		}
		v = d.back();
		for (auto u: ad[v]) {
			if (!mrk[u]) {
				s = 1;
				d.push_back(u);
				mrk[u] = 1;
				break;
			}
		}
	}
	cout << d.size() << endl;
	for (auto i: d) 
		cout << i << " ";
	return 0;
}
