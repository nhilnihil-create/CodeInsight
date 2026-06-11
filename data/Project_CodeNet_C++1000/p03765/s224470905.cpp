#include <bits/stdc++.h>
using namespace std;

const int MAXN = 112345;

string s, t;
int sums[MAXN][2], sumt[MAXN][2];

// 0 -> Da pra transformar em ''
// 1 -> Da pra transformar em A
// 2 -> Da pra transformar em B
int getState (int a, int b) {
	// cout << a << " e " << b << endl;
	int d = a - b;
	d %= 3;
	d += 3;
	
	return d % 3;
}

int main () {

	ios :: sync_with_stdio (false); cin.tie (0);
	
	cin >> s >> t;
	
	for (int i = 1; i <= s.size(); ++i) {
		int c = s[i - 1] - 'A';
		sums[i][c] = 1 + sums[i - 1][c];
		sums[i][c ^ 1] = sums[i - 1][c ^ 1];
	}
	
	for (int i = 1; i <= t.size(); ++i) {
		int c = t[i - 1] - 'A';
		sumt[i][c] = 1 + sumt[i - 1][c];
		sumt[i][c ^ 1] = sumt[i - 1][c ^ 1];
	}
	
	
	int q;
	cin >> q;
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a > b) swap (a, b);
		if (c > d) swap (c, d);
		int s1 = getState (sums[b][0] - sums[a - 1][0], sums[b][1] - sums[a - 1][1]);
		int s2 = getState (sumt[d][0] - sumt[c - 1][0], sumt[d][1] - sumt[c - 1][1]);
		
		// cout << s1 << " " << s2 << endl;
		if (s1 == s2)
			printf ("YES\n");
		else
			printf ("NO\n");
	}

	return 0;
}