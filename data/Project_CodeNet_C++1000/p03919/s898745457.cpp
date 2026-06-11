#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
#define int long long
#define rep(i,a,n) for (int (i)=(a);(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef long double ld;
signed  main() {
	/*int n, sum = 0, ans = 0;
	string s;
	cin >> s;
	n = s.size();
	for (int i = 0; i < floor(n / 2.0); i++) {
		if (s[i] == s[n - i - 1])
			sum++;
	}
	for (int i = 0; i < n; i++) {
		if (n % 2 == 1 && i == ceil(n / 2.0)-1)
			continue;
		for (int j = 0; j < 26; j++) {
			if ((int)s[i] - 'A' != j) {
				if (i > floor(n / 2.0) && ((char)j + 'A' != s[i - (floor(n / 2.0))] || (char)j + 'A' == s[i - (floor(n / 2.0))-1] && sum + 1 != (sum - sum % 2) / 2)) {
					if (sum == 0 || s[i] == s[n - i - 1])
						ans++;
				}
				else if (i < floor(n / 2.0) && ((char)j + 'A' != s[i - (floor(n / 2.0))] || (char)j + 'A' == s[n-i-1] && sum + 1 != (sum - sum % 2) / 2)) {
					if (sum == 0 || s[i] == s[n - i - 1])
						ans++;
				}
			}
		}
	}
	if (n % 2 == 1 && sum == 0)
		ans += 25;
	if (n == 1)
		ans = 0;
	cout << ans << endl;*/
	int h, w;
	cin >> h >> w;
	string s;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> s;
			if (s == "snuke") {
				cout << (char)(j + 'A') << i + 1 << endl;
			}
		}
	}
	getchar(); getchar();
}