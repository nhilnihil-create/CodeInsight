
// D - Simple Knapsack

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

using Weight = int;
using Values = vector<ll>;
using Items = map<Weight, Values>;

int N, W;
Items items;
ll ans = 0;

void dfs(Items& items, Items::iterator itr, vector<int>& nums) {
	if (itr == items.end()) {
		ll value_sum = 0;
		ll weight_sum = 0;

		int i=0;
		for (auto& itr : items) {
			ll w = itr.first;
			Values values = itr.second;
			for (int j=0; j<nums[i]; j++) {
				value_sum += values[j];
				weight_sum += w;
			}
			i++;
		}

		if (weight_sum <= W) {
			ans = max(ans, value_sum);
		}

		return;
	}

	for (int n=0; n <= itr->second.size(); n++) {
		nums.push_back(n);
		dfs(items, next(itr), nums);
		nums.pop_back();
	}
}

int main() {
	cin >> N >> W;

	ll w, v;
	for (int i=0; i<N; i++) {
		cin >> w >> v;
		items[w].push_back(v);
	}

	for (auto& itr : items) {
		sort(itr.second.begin(), itr.second.end(), greater<ll>());
	}

	vector<int> nums;
	dfs(items, items.begin(), nums);

	cout << ans << endl;

	return 0;
}