#include <bits/stdc++.h>
using namespace std;
#define mid ((s + e) / 2)
#define makefast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define comp(x) (lower_bound(vec.begin(), vec.end(), x) - vec.begin())
long long M = 1e9 + 7;
//>>>>>>>>>>>>>>>>>>>

const int N = 1e6 + 7;

int n;
int x[N];
int a[N];
int ord[N];
int main() {
	makefast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		a[x[i]] = i;
		ord[i] = i;
	}
	sort (ord + 1, ord + n + 1, [](int v, int u) {
		return x[v] < x[u];		
	});
	int pnt = n * n;
	for (int i = n; i >= 1; i--) {
		int v = ord[i];
		for (int j = 1; j <= n - v; j++) {
			while (a[pnt]) {
				pnt--;
			}
			if (pnt < x[v]) {
				cout << "No";
				return 0;
			}
			a[pnt] = v;
		}
	}
	pnt = 1;
	for (int i = 1; i <= n; i++) {
		int v = ord[i];
		for (int j = 1; j <= v - 1; j++) {
			while (a[pnt])
				pnt++;
			if (x[v] < pnt) {
				cout << "No";
				return 0;
			}
			a[pnt] = v;
		}
	}
	cout << "Yes" << '\n';
	for (int i = 1; i <= n * n; i++)
		cout << a[i] << ' ';

}
