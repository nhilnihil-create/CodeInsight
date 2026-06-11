#include <bits/stdc++.h>
using namespace std;
const int maxn = 123456;
vector<int> e[maxn];
int solve(int u){
	vector<int> sons;
	for(int v : e[u]) sons.push_back(solve(v));
	sort(sons.begin(), sons.end());
	for(int i = 0; i < e[u].size(); i++) sons[i] += e[u].size() - i;
	int mx = 0;
	for(int v : sons) mx = max(mx, v);
	return mx;
}
int main(){
	int n; cin >> n;
	for(int i = 2; i <= n; i++){
		int x; cin >> x;
		e[x].push_back(i);
	}
	cout << solve(1) << endl;
	return 0;
}
