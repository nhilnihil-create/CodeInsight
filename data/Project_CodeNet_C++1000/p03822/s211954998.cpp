#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int cnt[100001];
vector<vector<int>>fight;

int solve(int n) {
	int ans = cnt[n];
	vector<int>win;
	for (int i = 0; i < fight[n].size(); i++) {
		win.push_back(solve(fight[n][i]));
	}
	sort(win.begin(), win.end());
	reverse(win.begin(), win.end());
	for (int i = 0; i < fight[n].size(); i++) {
		win[i] += i + 1;
		ans = max(ans, win[i]);
	}

	return ans;
}

int main()
{
	int N; cin >> N;
	fight.resize(N+1);
	for (int i = 2; i <= N; i++) {
		int a;
		cin >> a;
		cnt[a]++;
		fight[a].push_back(i);
	}

	cout << solve(1) << endl;

    return 0;
}