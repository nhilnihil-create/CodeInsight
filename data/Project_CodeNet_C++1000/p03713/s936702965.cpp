#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <iomanip>
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
using vi = vector<int>;
using vll = vector<ll>;
ll mod = 1e9 + 7;

using namespace std;
using Graph = vector<vector<int>>;
Graph G;
const int AMAX = 100000;
/*int cnt_digit(ll N)
{
	int digit = 0;

	while (N > 0)
	{
		N /= 10;
		digit++;
	}
	return digit;
}

int n;
vll a;

ll solve(bool isp)
{
	ll sum = 0ll;
	ll ret = 0ll;

	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		if (isp and sum <= 0)
		{
			ret += -sum + 1;
			sum = 1ll;
		}
		if (not isp and sum >= 0)
		{
			ret += sum + 1;
			sum = -1ll;
		}
		isp ^= 1;
	}
	return ret;
}

*/
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	
	/*ll N, K;
	cin >> N >> K;
	ll t1 = N%K;
	ll t2 = abs(t1 - K);

	ll ans = min(t1, t2);
	

	cout << ans << endl;*/
	ll H, W;
	//vector<ll> S(AMAX + 1);
	cin >> H >> W;
	ll ans = H * W;
	ll s[3];
	for (int i = 0; i < 2; i++)
	{
		for (int h = 1; h <= H; h++)
		{
			//まずは縦割り
			s[0] = h * W;
			s[1] = (H - h) * (W / 2);
			s[2] = H * W - (s[0] + s[1]);
			sort(s, s + 3);
			ans = min(ans, s[2] - s[0]);

			//次いで横割り
			s[0] = h * W;
			s[1] = ((H - h) / 2) * W;
			s[2] = H * W - (s[0] + s[1]);
			sort(s, s + 3);
			ans = min(ans, s[2] - s[0]);
			
		}
		//板チョコを90度回す。
		swap(H, W);

	}
	cout << ans << endl;
	return 0;

}