#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	int s[n];
	int sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		sum += s[i];
	}
	sort(s, s + n);

	if(sum % 10 == 0) {
		bool sub = false;
		for (int i = 0; i < n; i++)
		{
			if(!sub && s[i] % 10 != 0) {
				sum -= s[i];
				sub = true;
			}
		}
	}

	if(sum % 10 != 0) cout << sum << endl;
	else cout << "0" << endl;
	return 0;
}
