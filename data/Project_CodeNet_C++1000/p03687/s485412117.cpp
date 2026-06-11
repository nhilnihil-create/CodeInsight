#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string s;
	cin >> s;

	int ans = 105;
	rep(i,26){
		int d = 0;
		int d_max = 0;
		rep(j,s.size()){
			if (s[j]-'a' != i) d++;
			else {
				d_max = max(d_max, d);
				d = 0;
			}
		}
		d_max = max(d_max, d);
		ans = min(ans, d_max);
	}

	cout << ans << endl;
return 0;
}
