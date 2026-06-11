#include <bits/stdc++.h>
using namespace std;

const int MN = 501;
int a[MN * MN], mx[MN], ptr, lst[MN];
void add(int v, bool b) {
	while (a[ptr])
		ptr++;
//	cerr << v << 'p' << ptr << 'b' << b << 'l' << lst[v] << endl;
	a[ptr] = v;
	if (!b) {
		if (ptr > lst[v])
			cout << "No\n", exit(0);
	} else
		if (ptr < lst[v])
			cout << "No\n", exit(0);
	ptr++;
}

int main() {
	int n;
	cin >> n;
	pair <int, int> x[MN];
	for (int i = 0; i < n; i++) {
		cin >> x[i].first;
		a[--x[i].first] = i + 1;
		x[i].second = i + 1;
		lst[i + 1] = x[i].first;
	}
	sort(x, x + n);
	for (int i = 0; i < n; i++) 
		for (int j = 1; j < x[i].second; j++)
			add(x[i].second, false);
	for (int i = 0; i < n; i++) 
		for (int j = x[i].second; j < n; j++)
			add(x[i].second, true);
	cout << "Yes" << endl;
	for (int i = 0; i < n * n; i++)
		cout << a[i] << endl;
}
