/* be name Khoda */
#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1001;
int n, a[N], numdif, maxi, mini = N;
bool dif;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	mini = a[0], maxi = a[n - 1];
	if (maxi - mini > 1)
		cout << "No";
	else {
		if (mini == maxi) {
			if (a[0] + 1 == n || 2 * a[0] <= n) 
				cout << "Yes";
			else
				cout << "No";
		}
		else {
			int nummini = 0, nummaxi = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] == maxi)
					nummaxi++;
				else 
					nummini++;
			}
			int bigger = maxi - nummini;
			if (maxi > nummini && 2 * bigger + nummini <= n)
				cout << "Yes";
			else
				cout << "No";
		}
	}
}
			