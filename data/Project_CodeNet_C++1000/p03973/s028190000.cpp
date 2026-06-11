#include <bits/stdc++.h>
using namespace std;
int main(){
	long long ans = 0, pass = 1, n;
	cin >> n;
	while(n--){
		long long x; cin >> x;
		if(x > pass){
			if(x % pass){
				ans += x / pass;
				x = 1;
			} else {
				ans += x / pass - 1;
				x = 1;
			}
		}
		pass = max(pass, x + 1);
	}
	cout << ans << endl;
	return 0;
}
