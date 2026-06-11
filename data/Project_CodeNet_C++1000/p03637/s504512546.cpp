#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>

#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	ll cnt4 = 0;
	ll cnt2 = 0;
	ll cnto = 0;
	rep(i, n) {
		if (a[i] % 4 == 0) {
			cnt4++;
		}
		else if (a[i] % 2 == 0) {
			cnt2++;
		}
		else {
			cnto++;
		}
	}
	if (cnt2 > 0) {
		cnto++;
	}
	cnto -= cnt4 + 1;
	//printf("%d %d\n", cnt4, cnt2);
	puts(cnto <= 0 ? "Yes" : "No");


	return 0;
}
