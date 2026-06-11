#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

Int n, ans, m = 1;
vector<Int> a;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	a.resize(n);
	for(auto &i:a) cin >> i;
	for(size_t i=0; i<a.size(); ++i){
		if(a[i] < m) continue;
		if(a[i] == m){
			++m;
		}else{
			ans += (a[i] - 1) / m;
			if(m == 1) ++m;
		}
	}
	cout << ans << "\n";
}