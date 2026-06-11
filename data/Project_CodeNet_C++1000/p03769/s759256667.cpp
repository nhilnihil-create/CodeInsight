#include <bits/stdc++.h>
using namespace std;
vector<int> solve(long long n) {
	if(n == 1) return vector<int>();
	if(n & 1) {
		vector<int> res = solve(n - 1);
		res.insert(res.begin(), res.size() + 1);
		return res;
	}
	vector<int> res = solve(n / 2);
	res.push_back(res.size() + 1);
	return res;
}
int main() {
	long long n;
	cin >> n;
	vector<int> ret = solve(n + 1);
	cout << ret.size() * 2 << endl;
	for(int i = 1; i <= ret.size(); i++) cout << i << ' ';
	for(int i : ret) cout << i << ' ';
	return 0;
}