#include "bits/stdc++.h"
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define all(V) (V).begin(), (V).end() 
using namespace std;
typedef long long ll;

int main() {fio;
	int n, l;
	cin >> n;
	ll ans = 0, sm = 0;
	while(n--) {
		int u;
		cin >> u;
		if(u == 0)  {
			ans += sm / 2;
			sm = 0;
		}
		sm += u;
	}
	ans += sm / 2;
	cout << ans << endl;
	return 0;
}