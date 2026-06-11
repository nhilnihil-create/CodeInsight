#include <bits/stdc++.h>
using namespace std;

#define sz(x) static_cast<int>((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using ld = long double;

template<class T> bool cmn(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool cmx(T &a, T b) { return a < b ? (a = b, true) : false; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int& x: vec) cin >> x;
	double avg = 0;
	for(int x : vec) avg += x;
	avg /= n;
	int val = (int) round(avg);
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		int go = abs(val - vec[i]);
		ans += go * go;
	}
	cout << ans << '\n';
	return 0;
}