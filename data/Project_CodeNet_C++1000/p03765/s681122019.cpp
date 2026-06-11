#include <bits/stdc++.h>
using namespace std;

int Q, N;
string s, t;

int fw[100005][2];
void update(int x, int v, int n) { //v is value, x is position
    for (;x <=N; x+=x&(-x)) fw[x][n] += v; 
}
int sum(int x, int n) {
    int res = 0;
    for(; x; x-=x&(-x)) res += fw[x][n];
    return res;
}
int rs(int x, int y, int n) {
	return sum(y, n) - sum(x-1, n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	N = max(s.length(), t.length());
	N++;
	for (int i = 0; i < (int) s.length(); i++) {
		update(i+1, s[i]-'A'+1, 0);
	}
	for (int i = 0; i < (int) t.length(); i++) {
		update(i+1, t[i]-'A'+1, 1);
	}
	cin >> Q;
	for (int q = 0; q < Q; q++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (rs(a, b, 0) % 3 == rs(c, d, 1) % 3) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
