#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

bool solve(Int n, vector<Int> &a){
	if(a.front() + 1 < a.back()) return false;
	if(a.front() == a.back()) return a.front() <= n / 2 || a.front() == n-1;
	Int cnt = 0;
	for(auto i:a)
		if(i == a.front())
			++cnt;
	return cnt + 1 <= a.back() && a.back() <= cnt + (n - cnt) / 2;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	Int n; cin >> n;
	vector<Int> a(n);
	a.resize(n);
	for(auto &i:a) cin >> i;
	sort(a.begin(), a.end());
	if(solve(n, a)) cout << "Yes\n";
	else cout << "No\n";
}