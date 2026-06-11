#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	string s;
	cin >> s;
	int n = s.size();
	int ans = 1e9;
	for (int i = 0; i < 26; i++) {
		char c = 'a' + i;
		int num1 = -1;
		int cnt = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (s[j] == c) {
				num1 = cnt;
				cnt = 0;
				break;
			} else
				cnt++;
		}
		int num2 = -1;
		for (int j = 0; j < n; j++) {
			if (s[j] == c) {
				num2 = max(num2, cnt);
				cnt = 0;
			} else
				cnt++;
		}
		int sum = max(num2, num1);
		if (num1 != -1){
			ans = min(ans, sum);
		}
	}
	cout << ans << endl;
}
