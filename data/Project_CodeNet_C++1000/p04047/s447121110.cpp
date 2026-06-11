#include <bits/stdc++.h>
using namespace std;
int a[105],ans; 
int main(){
	int i,x;
	ios::sync_with_stdio(0);
	cin >> i,i <<= 1; while (i--) cin >> x,++a[x];
	for (x = 0,i = 100; i ; --i){
		ans += i * (a[i]>>1);
		if (a[i] & 1){ if (!x) x = 1; else ans += i,x = 0; }
	}
	cout << ans << '\n';
	return 0;
}