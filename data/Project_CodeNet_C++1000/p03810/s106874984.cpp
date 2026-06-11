#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int a[MAXN], n;
string str[2] = {"First", "Second"};

inline int gcd(int a, int b)
{ return b == 0 ? a : gcd(b, a%b); }

void solve(int a[], int n, int cur)
{
	int even = 0, odd = 0;
	for (int i = 1; i <= n; i++) {
	        if (a[i]&1) odd++;
		else even++;
	}
	if (odd == 1) {
		if (even&1) cout << str[cur] << endl;
		else {
			for (int i = 1; i <= n; i++)
				if (a[i]&1) {
					if (a[i] == 1) {
						cout << str[cur^1] << endl;
						return;
					}
					a[i]--;
					break;
				}
			int g = a[1];
			for (int i = 2; i <= n; i++)
				g = gcd(g, a[i]);
			for (int i = 1; i <= n; i++)
				a[i] /= g;
			solve(a, n, cur^1);
		}
	} else {
		if (even&1) cout << str[cur] << endl;
		else cout << str[cur^1] << endl;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	solve(a, n, 0);
	return 0;
}
