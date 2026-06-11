#include <bits/stdc++.h>
using namespace std;

#define sz size
#define pb push_back

const int N = 1e5 + 123;

int n, m, sum, cnt[N];
int main() {
	//freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int l, r;
		cin >> l >> r;
		cnt[l]++;
		cnt[r]--;
	}
	for(int i = 1; i < n; ++i) {
		sum += cnt[i];
		if(sum % 2 != 0) {
			cout << "NO";
			return 0;
		}
	}	
	cout << "YES";
}