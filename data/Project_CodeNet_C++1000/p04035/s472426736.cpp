#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N, L;
	cin >> N >> L;
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];

	int t = -1;
	for(int i = 0; i < N - 1; i++)
		if(a[i] + a[i + 1] >= L) {
			t = i;
			break;
		}
	if(t == -1) {
		cout << "Impossible";
		return 0;
	}
	cout << "Possible\n";
	for(int i = 0; i < N - 1; i++) {
		if(i == t) break;
		cout << i + 1 << "\n";
	}
	for(int i = N - 2; i >= 0; i--) {
		if(i == t) break;
		cout << i + 1 << "\n";
	}
	cout << t + 1 << "\n";
	return 0;
}