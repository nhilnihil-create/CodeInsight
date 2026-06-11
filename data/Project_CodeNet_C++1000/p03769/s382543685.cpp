#include <bits/stdc++.h>
using namespace std;
vector<int> solve(long long n, int tp){
	if(n == 1){
		vector<int> ans;
		return ans;
	}
	if(n & 1){
		vector<int> sol = solve(n - 1, tp + 1);
		sol.push_back(tp);
		return sol;
	}
	vector<int> sol = solve(n / 2, tp + 1);
	sol.insert(sol.begin(), tp);
	return sol;
}
int main(){
	long long n; cin >> n; n++;
	vector<int> sol = solve(n, 1);
	vector<int> cpy = sol;
	sort(cpy.begin(), cpy.end());
	cout << 2 * sol.size() << endl;
	for(int v : sol) cout << v << " ";
	for(int v : cpy) cout << v << " ";
	cout << endl;
	return 0;
}
