#include <bits/stdc++.h>
using namespace std;

int n, m, num, cnt;
vector<int> a, b;

void kill() {
	cout << "Impossible";
	exit(0);
}

void add(int l) {
	if(l)
		b.push_back(l);
}

void print() {
	for (int num: a)
		cout << num << ' ';
	cout << '\n' << b.size() << '\n';
	for (int num: b)
		cout << num << ' ';
}

void solve_odd() {
	if(cnt > 1)
		kill();
	for (int i = 0; i < m; i++)
		if(a[i] & 1)
			swap(a[i], a[m - 1]);
	for (int i = 0; i < m; i++)
		if(i == 0)
			add(a[i] + 1);
		else if(i == m - 1)
			add(a[i] - 1);
		else
			add(a[i]);
	print();
}

void solve_even() {
	if(cnt > 2)
		kill();
	for (int i = 0; i < m; i++)
		if(a[i] & 1)
			swap(a[i], a[0]);
	for (int i = 1; i < m; i++)
		if(a[i] & 1)
			swap(a[i], a[m - 1]);
	for (int i = 0; i < m; i++)
		if(i == m - 1)
			add(a[i] - 1);
		else if(i == 0)
			add(a[i] + 1);
		else
			add(a[i]);
	print();
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		cnt += (num & 1);
		a.push_back(num);
	}
	if(m == 1) {
		if(n % 2 == 1)
			add(n >> 1), add((n + 1) >> 1);
		else
			add(n / 2 + 1), add(n / 2 - 1);
		print();
	}
	else if(n & 1)
		solve_odd();
	else
		solve_even();
	return 0;
}