#include <bits/stdc++.h>
using namespace std;
 
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int s[n], sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		sum += s[i];
	}
	sort (s, s + n);
	int i = 0;
	if (sum % 10) cout << sum;
	else {
		while (i < n && s[i] % 10 == 0)
			i++;
		if (i == n) 
			cout << 0;
		else 
			cout << sum - s[i];
	}
}