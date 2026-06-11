#include <bits/stdc++.h>
using namespace std;

const int N = 110;

char str[N][N];

int frq[30];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> str[i];
	
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) frq[str[i][j] - 'a']++;
	for (int i = 0; i < 30; i++) frq[i] %= 4;
	
	int cnt = 0;
	for (int i = 0; i < 30; i++) if (frq[i] & 1) cnt++;
	if (cnt > 1) {
		cout << "No\n";
		return 0;
	}
	int tot = 0;
	for (int i = 0; i < 30; i++) tot += frq[i];
	
	int chk = 0;
	if (m & 1) chk += n;
	if (n & 1) chk += m;
	if (m % 2 && n % 2) chk--;
	
	cout << ((chk >= tot) ? "Yes" : "No") << "\n";
	
	return 0;
}
