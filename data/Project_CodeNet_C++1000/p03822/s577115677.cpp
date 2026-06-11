//人bが人aに初めて負けたとき、aからbに辺を張ったグラフGを考える.
//a -> {b_1, b_2, …, b_k}と辺が張ってあるとき、b_i(1≦i≦k)についてトーナメントの深さを最小化し、その値をv(b_i)とおく。
//v(b_i)の大きい順にbを並べ、v(b_i + i)のmaxを取ったものがv(a)になりそうだ。
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int n;
vector<int> et[100000];
int dp[100000];

int dfs(int v) {
	if (dp[v] != -1) return dp[v];
	
	int ret = 0;
	vector<int> vec;
	for (int i = 0; i < et[v].size(); i++) {
		int nv = et[v][i];
		int res = dfs(nv);
		vec.push_back(res);
	}
	sort(vec.begin(), vec.end(), greater<int>());
	
	for (int i = 0; i < vec.size(); i++) {
		int res = vec[i] + i + 1;
		ret = max(ret, res);
	}
	return dp[v] = ret;
}

int main() {
	int i;
	
	cin >> n;
	for (i = 1; i < n; i++) {
		int a;
		cin >> a; a--;
		et[a].push_back(i);
	}
	
	for (i = 0; i < n; i++) dp[i] = -1;
	
	int ans = 0;
	for (i = 0; i < n; i++) {
		int res = dfs(i);
		ans = max(ans, res);
	}
	cout << ans << endl;
	return 0;
}