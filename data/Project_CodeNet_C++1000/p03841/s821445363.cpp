#include <bits/stdc++.h>
 
using namespace std;
 
#define debug(a) cerr << #a << ": " << a << endl
 
typedef long long ll;
typedef pair<int, int> ii;
 
#define x first
#define y second
 
const int N = 505;

void impossible() {
	cout << "No" << endl;
	exit(EXIT_SUCCESS);
}

int n;
ii x[N];
int a[N * N];

int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif
 
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> x[i].x;
		x[i].y = i;
	}

	sort(x + 1, x + n + 1);

	int at = 1, tot = n * n;
	for (int i = 1; i <= n; i++) {
		int ends = x[i].x;
		int num = x[i].y;

		for (int j = 1; j <= num - 1; j++) {
			while (at <= tot && a[at] != 0) at++;
			if (at > tot) impossible();
			a[at] = num;
			at++;
		}

		if (at > ends) impossible();
		a[ends] = num;
	}

	queue<int> q;
	x[n + 1].x = tot;

	for (int i = 0; i <= n; i++) {
		if (i > 0)
			for (int j = 1; j <= n - x[i].y; j++)
				q.push(x[i].y);

		for (int j = x[i].x + 1; j <= x[i + 1].x; j++) {
			if (a[j] == 0) {
				if (q.empty()) impossible();
				else {
					a[j] = q.front();
					q.pop();
				}
			}
		}
	}

	cout << "Yes" << endl;
	for (int i = 1; i <= tot; i++) cout << a[i] << " ";
 	
	return 0;
}