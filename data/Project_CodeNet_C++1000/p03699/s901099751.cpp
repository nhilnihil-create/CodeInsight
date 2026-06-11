#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

int main(void){
	cin >> n;
	vector<int> s(n);
	lli ans = 0;
	rep(i, n){
		cin >> s[i];
		ans += s[i];
	}
	sort(s.begin(), s.end());
	if(ans%10 != 0){
		cout << ans << endl;
		return 0;
	}
	bool f = true;
	rep(i, n){
		if(s[i] %10 != 0){
			f = false;
			ans -= s[i];
			break;
		}
	}
	if(f) cout << 0 << endl;
	else cout << ans << endl;
	return 0;
}
