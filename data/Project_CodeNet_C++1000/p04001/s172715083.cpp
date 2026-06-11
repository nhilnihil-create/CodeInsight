#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
	string S; cin >> S;
	ll bitnum = S.length() - 1;
	ll ans = 0;
	rep(i,(1<<bitnum)) {
		string tmp = "";
		int index = 0;
		rep(j,bitnum){
			tmp += S[index];
			if (i >> j & 0x01) {
				ans += atol(tmp.c_str());
				tmp = "";
			}
			else {
			}
			index++;
		}
		tmp += S[index];
		ans += atol(tmp.c_str());
	}
	cout << ans << endl;


}
