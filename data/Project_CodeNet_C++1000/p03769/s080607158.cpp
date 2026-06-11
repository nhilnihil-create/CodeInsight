#include<bits/stdc++.h>
using namespace std;

long long n, a = 1, b = 100;
vector<int> ans;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= 100; i++)
		ans.push_back(i);
	while (n) {
		if (n & 1) {
			ans.push_back(a++);
			n >>= 1;
		}
		else {
			ans.push_back(b--);
			n--;
		}
	}
	cout << ans.size() << '\n';
	for (int x: ans)
		cout << x << ' ';
}