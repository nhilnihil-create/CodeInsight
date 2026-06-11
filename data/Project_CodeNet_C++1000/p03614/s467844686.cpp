#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<numeric>
#include<queue>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, p;
	int ans = 0;
	cin >> n;
	bool mask = false;
	for (int i = 0; i < n; i++) {
		cin >> p;
		if (mask) { mask = false; }
		else if (p-1==i){
			ans++;
			mask = true; 
		}
	}
	cout << ans << endl;

	return 0;
}