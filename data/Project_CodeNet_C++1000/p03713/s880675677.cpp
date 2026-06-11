#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>

using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
const ll MOD = 1e9 + 7;


int main() {
	ll H, W;
	cin >> H >> W;
	vll ans;
	if (H % 3 == 0 || W % 3 == 0) {
		cout << 0 << endl;
	}
	else if (H == 1 || W == 1) {
		cout << 1 << endl;
	}
	else {
		ll S1, S2, S3;
		ll maxi;
		ll mini;
		ll kouho;
		repp(i, H-1) {
			S1 = i * W;
			S2 = (H - i) * (W / 2);
			S3 = H * W - S1 - S2;
			maxi = max(S1, max(S2, S3));
			mini = min(S1, min(S2, S3));
			kouho =  maxi - mini;
			ans.push_back(kouho);
		}
		repp(i, W-1) {
			S1 = i * H;
			S2 = (W - i) * (H / 2);
			S3 = H * W - S1 - S2;
			maxi = max(S1, max(S2, S3));
			mini = min(S1, min(S2, S3));
			kouho = maxi - mini;
			ans.push_back(kouho);
		}
		ans.push_back(H);
		ans.push_back(W);
		sort(ans);
		cout << ans[0] << endl;
	}
}