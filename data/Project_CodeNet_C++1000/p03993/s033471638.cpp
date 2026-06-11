#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec.at(i);
		vec.at(i)--;
	}
	vector<set<int>> wait(n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (wait.at(i).count(vec.at(i))) {
			ans++;
		}
		else {
			wait.at(vec.at(i)).insert(i);
		}
	}
	cout << ans << endl;
}