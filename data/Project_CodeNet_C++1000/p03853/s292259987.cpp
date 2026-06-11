#include <bits/stdc++.h>
using namespace std;

const int N = 1100;

char pan[N][N];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> pan[i];
	for (int i = 0; i < n + n; i++) cout << pan[i / 2] << "\n"; 
	
	return 0;
}
