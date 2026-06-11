#include <bits/stdc++.h>


using namespace std;



const int MAXN = 500 + 23;







int n, x[MAXN], z[MAXN * MAXN];
bitset<MAXN * MAXN> mark;


struct cmp {
	bool operator () (int a, int b) {
		return x[a] <= x[b];
	}
};
struct cmp2 {
	bool operator () (int a, int b) {
		return x[a] >= x[b];
	}
};


set<int, cmp> s;
set<int, cmp2> t;




int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		x[i]--;
		z[x[i]] = i;
		mark[x[i]] = true;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			s.insert(i);
	for (int i = 0; i < n * n; i++) if (!mark[i]) {
		if (s.empty()) break;
		int f = *s.begin();
		s.erase(s.begin());
		if (x[f] < i) return cout << "No", 0;
		z[i] = f;
		mark[i] = true;
	}
	if (!s.empty()) return cout << "No", 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n - 1; j++)
			t.insert(i);
	for (int i = n * n - 1; ~i; i--) if (!mark[i]) {
		if (t.empty()) break;
		int f = *t.begin();
		t.erase(t.begin());
		if (x[f] > i) return cout << "No", 0;
		z[i] = f;
		mark[i] = true;
	}
	if (!t.empty()) return cout << "No", 0;
	cout << "Yes\n";
	for (int i = 0; i < n * n; i++) cout << z[i] + 1 << ' ';
	return 0;
}