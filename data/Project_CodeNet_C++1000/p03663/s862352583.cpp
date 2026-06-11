#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll ten8 = 1e8;
const ll ten9 = 1e9;
const ll ten10 = 1e10;
const ll n8 = 1e8-1;
const ll n9 = 1e9-1;
const ll n10 = 1e10-1;

int main(){
	bool allnine = true;
	ios_base::sync_with_stdio(0);
	ll x, ans = 0;
	char res;
	while(1){
		ll l = 0, r = 9;
		ll suf = n10;
		if(ans > 1e5)
			suf = n8;
		while(l < r){
			ll nd = (l+r)/2;
			if(ans == 0 && nd == 0){
				l = r = 1;
				break;
			}
			cout << "? " << ans*10+nd << suf << endl;
			cout.flush();
			cin >> res;
			if(res == 'Y')
				r = nd;
			else l = nd+1;
		}
		ans = ans*10 + l;
		if(l != 9)
			allnine = false;
		cout << "? " << ans+1 << endl;
		cout.flush();
		cin >> res;
		if(res == 'Y' && allnine == false || res == 'N' && allnine){
			cout << "! " << ans << endl;
			return 0;
		}
	}
}