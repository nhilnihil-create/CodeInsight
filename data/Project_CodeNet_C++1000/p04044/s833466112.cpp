#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, l;
	string a[101];
	cin >> n >> l;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	for(int i=0; i<n; i++) {
		cout << a[i];
	}
	return 0;
}
