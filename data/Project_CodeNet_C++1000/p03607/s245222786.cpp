#include<iostream>
#include<map>
using namespace std;

int main() {
	int n; cin >> n;
	map<int, int>a;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		a[tmp]++;
	}
	
	int ans = 0;
	for (auto&& x : a) {
		if (x.second % 2 == 1)ans++;
	}
	cout << ans << endl;
	
	return 0;
}