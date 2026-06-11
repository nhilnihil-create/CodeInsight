//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2 * 100 * 100 + 17;

ll n, p[MAXN], b[MAXN], a[MAXN], fen[MAXN];

void add(int x) {
	for (;x <= n; x += x & -x)
		fen[x]++;
}
int get(int x) {
	int res = 0;
	for (; x; x -= x & -x)
		res += fen[x];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i], a[p[i] + 1]++, b[1]++, b[p[i]]--;
	for (int i = 1; i <= n; i++)
		a[i] += a[i - 1], b[i] += b[i - 1];
	for (int i = n; i; i--) {
		int t = get(p[i]);
		a[p[i]] -= t;
		b[p[i]] -= n - i - t;
		add(p[i]);
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] + i * (n + 1) << ' ';
	cout << endl;
	for (int i = 1; i <= n; i++)
		cout << b[i] + (n - i + 1) * (n + 1) << ' ';
	cout << endl;
	return 0;
}
