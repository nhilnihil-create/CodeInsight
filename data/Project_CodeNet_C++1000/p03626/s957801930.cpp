#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
const int MOD = 1000000007;
using namespace std;

int main() {
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	int count = 1;
	vector<int> a;
	for (int i = 0; i < s1.size() - 1; i++) {
		if (s1[i] == s1[i + 1])
			count++;
		else {
			a.push_back(count);
			count = 1;
		}
	}
	a.push_back(count);
	ll ans;
	if (a[0] == 2)
		ans = 6;
	else
		ans = 3;
	for (int i = 1; i < a.size(); i++) {
		if (a[i - 1] == 1 && a[i] == 1)
			ans = ans * 2 % MOD;
		else if (a[i - 1] == 1 && a[i] == 2)
			ans = ans * 2 % MOD;
		else if (a[i - 1] == 2 && a[i] == 2)
			ans = ans * 3 % MOD;
	}
	cout << ans << endl;
	return 0;
}