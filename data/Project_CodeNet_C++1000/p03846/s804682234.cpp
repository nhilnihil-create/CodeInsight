#include <bits/stdc++.h>
using namespace std;
#define dhoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);  
typedef long long ll;
typedef long double ld;
const ll inf = 1e18;
const int nax = 2e6 + 7;
const ll mod = 1e9 + 7;
//ll tree[4 * nax];
//9uS-22RSwk7gQqh
map< int , int > mp;
int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		mp[x]++;
	} 
	int cnt = 0;
	for(auto it : mp){
		if(it.second == 2)
			cnt++;
	}
	if(cnt != n/2)
	{
		cout << 0 << endl;
		return 0;
	}
	if(n % 2 && mp[0] == 2){
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1;
	for(int i = 0 ; i < n/2 ; i++){
		ans = (ans * 2)%mod;
	}
	cout << ans << endl;
	return 0;
}

