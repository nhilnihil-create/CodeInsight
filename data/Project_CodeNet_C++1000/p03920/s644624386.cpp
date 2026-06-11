#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;
	ll k = 1;
	while((k + 1) * (k + 0) / 2 < N) k++;
	//cout << k << endl;

	vector<int> ans;
	for(int i = k; i >= 1; i--) {
		if(i <= N) {
			N -= i;
			ans.push_back(i);
		}
	}

	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}