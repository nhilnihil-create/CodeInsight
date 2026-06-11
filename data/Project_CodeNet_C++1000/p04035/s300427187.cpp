#include "bits/stdc++.h"
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define all(V) (V).begin(), (V).end() 
using namespace std;
typedef long long ll;

int main() {fio;
	int n, l;
	cin >> n >> l;
	vector <int> a(n);
	for(int &u : a) cin >> u;
	pair <int, int> best = {-1, -1};
	for(int i = 0; i < n - 1; i++) {
		best = max(best, {a[i] + a[i + 1], i});
	}
	if(best.first < l) {
		cout << "Impossible";
	} else {
		cout << "Possible\n";
		// for(int i = 0; i < n - 1; i++) {
		// 	cout << (best.second + 1 + i) % (n - 1) + 1 << endl;
		// }
		// cout << best.second << endl;
		for(int i = n - 1; i >= best.second + 2; i--) {
			cout << i << endl;
		}
		for(int j = 0; j <= best.second; j++) {
			cout << j + 1 << endl;
		}
	}
    return 0;
}