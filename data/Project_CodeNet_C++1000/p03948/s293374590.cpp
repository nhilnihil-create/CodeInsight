#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<numeric>
#include <unordered_map>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, t, a, ans;
	int mina = INT32_MAX;
	int maxp = -1;
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < mina) {
			mina = a;
		}
		else if(mina + maxp == a){
			ans++;
		}
		else if (mina + maxp < a) {
			ans = 1;
			maxp = a - mina;
		}
	}
	cout << ans << endl;
	return 0;
}