#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> mod(m);
	vector<int> pr(m);
	int ans = 0;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		mod[i] = 0;
		pr[i] = 0;
	}
	
	sort(a.begin(), a.end());
	
	mod[a[0] % m]++;
	for(int i = 1; i < n; i++){
		mod[a[i] % m]++;
		if(a[i] == a[i-1]){
			pr[a[i] % m] += 2;
			a[i] *= -1;
			a[i-1] *= -1;
		}
	}
	
	ans += mod[0] / 2;
	for(int i = 1; i < (m+1) / 2; i++){
		int tmp = min(mod[i], mod[m - i]);
		ans += tmp;
		mod[i] -= tmp;
		mod[m - i] -= tmp;
	}
	if(m % 2 == 0){
		ans += mod[m / 2] / 2;
		mod[m / 2] %= 2;
	}
	
	for(int i = 1; i < m; i++){
		ans += min(mod[i] / 2, pr[i] / 2);
	}
	
	cout << ans << endl;
	
	return 0;
}