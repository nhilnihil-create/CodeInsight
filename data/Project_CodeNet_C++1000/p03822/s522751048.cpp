#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dfs(vector<vector<int>> &c, int v = 0){
	int deg = c[v].size();
	vector<int> x;
	for (int w : c[v]){
		x.push_back(dfs(c, w));
	}
	sort(x.begin(), x.end());
	reverse(x.begin(), x.end());
	int ans = 0;
	for (int i = 0; i < deg; i++){
		ans = max(ans, x[i] + i);
	}
	ans++;
	return ans;
}
int main(){
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 1; i < N; i++){
		cin >> a[i];
		a[i]--;
	}
	vector<vector<int>> c(N);
	for (int i = 1; i < N; i++){
		c[a[i]].push_back(i);
	}
	cout << dfs(c) - 1 << endl;
}