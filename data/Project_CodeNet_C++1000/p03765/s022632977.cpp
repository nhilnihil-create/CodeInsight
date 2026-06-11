#include <bits/stdc++.h>
#define LL long long
#define PII pair<int, int>
#define F first
#define S second 
using namespace std;
const LL INF = (LL) 1e9 + 5;
const LL MOD = (LL) 1e9 + 7;
const int MAXN = 100005;

int qn, p1[MAXN], p2[MAXN];
string s, t;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s >> t >> qn;
	for (int i = 0; i < s.size(); i++) {
		p1[i + 1] = (s[i] == 'A' ? 1 : -1);
		p1[i + 1] += p1[i];
	}
	for (int i = 0; i < t.size(); i++) {
		p2[i + 1] = (t[i] == 'A' ? 1 : -1);
		p2[i + 1] += p2[i];
	}
	
	for (int i = 0; i < qn; i++) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		
		int c1 = p1[r1] - p1[l1 - 1], c2 = p2[r2] - p2[l2 - 1];
		c1 = (c1 % 3 + 3) % 3;
		c2 = (c2 % 3 + 3) % 3;
		cout << (c1 == c2 ? "YES\n" : "NO\n");
	}

	return 0;
}