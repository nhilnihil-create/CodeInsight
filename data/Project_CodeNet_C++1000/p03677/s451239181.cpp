#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::cin;

int main(){
	int n, m; cin >> n >> m; std::vector<long> li(2 * m + 1, 0);
	std::vector<long> a(n); for(int i = 0; i < n; i++) cin >> a[i];
	
	std::vector<std::vector<int>> vec(m + 1);
	for(int i = 0; i < n - 1; i++){
		if(a[i] < a[i + 1]){
			li[a[i] + 1]++;
			li[a[i + 1]]--;
		}else{
			li[a[i] + 1]++;
			li[a[i + 1] + m]--;
		}
		
		vec[a[i + 1]].push_back(i);
	}
	for(int i = 0; i < 2 * m - 1; i++) li[i + 1] += li[i];
	for(int i = 0; i < m; i++) li[i] += li[i + m];
	
	long pos = 0;
	for(int i = 0; i < n - 1; i++){
		pos += std::min((a[i + 1] + m - a[i]) % m, 1 + (a[i + 1] + m - 1) % m);
	}
	
	long mi = pos;
	for(int i = 1; i < m; i++){
		pos -= li[i];
		
		for(auto v : vec[i]){
			pos -= 1 + (a[v + 1] + m - i) % m;
			pos += (a[v + 1] + m - a[v]) % m;
		}
	
		mi = std::min(mi, pos);
	}
	
	cout << mi << endl;
	return 0;
}
