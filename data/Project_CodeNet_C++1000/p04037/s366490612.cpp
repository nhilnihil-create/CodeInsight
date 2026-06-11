/* In the name of Allah */
#include<bits/stdc++.h>
using namespace std;

int n, a[100005];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n, greater<int>());
	for (int i = 1; i <= n; i++)
		if (a[i] <= i) {
			int k = 0;
			while (a[i + k] == i)
				k++;
			return !printf(k & 1 || a[i - 1] - i & 1? "First": "Second");
		}
}
