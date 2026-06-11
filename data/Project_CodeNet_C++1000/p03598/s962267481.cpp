#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	int x[100];
	cin >> n >> k;
	for(int i = 0; i < n; ++i){
		cin >> x[i];
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
	int tmp = min(x[i], k - x[i]);
		ans += tmp;
	}
	cout << ans*2 << "\n";
}