// In The Namw Of Allah
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
typedef pair <int, int> pii;
typedef long long ll;

int a[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	sort(a, a + n);
	if(a[n - 1] - a[0] > 1)
		cout << "No\n";
	else {
		if(a[n - 1] == a[0]) {
			if(a[0] == n - 1 || a[0] * 2 <= n)	cout << "Yes\n";
			else	cout << "No\n";
		}
		else {
			int c = 0;
			for (int i = 0; i < n; i++)
				c += (a[i] == a[0]);
			int t = n - c;
			if(a[n - 1] <= c + t / 2 && a[n - 1] > c)	cout << "Yes\n";
			else	cout << "No\n";
		}
	}
}