#include <bits/stdc++.h>
#define sp ' '
#define nyan "(=^・ω・^=)"
#define mkp make_pair
#define intmax 2147483647
#define llmax 9223372036854775807
#define lP pair<ll,ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;
const int mod = 1000000007;
const int mod998 = 998244353;

int H, W, h, w;

int main() {
	cin >> H >> W >> h >> w;
	if (H%h) {
		cout << "Yes" << endl;
		for (int i = 0; i != H; ++i) {
			for (int j = 0; j != W; ++j) {
				if (i % h == 0)
					cout << 0xe869120;
				else if (i % h == h - 1)
					cout << -0xe869121;
				else
					cout << 0;
				if (j != W - 1)
					cout << sp;
			}
			cout << endl;
		}
	}
	else if (W%w) {
		cout << "Yes" << endl;
		for (int i = 0; i != H; ++i) {
			for (int j = 0; j != W; ++j) {
				if (j%w == 0)
					cout << 0xe869120;
				else if (j%w == w - 1)
					cout << -0xe869121;
				else
					cout << 0;
				if (j != W - 1)
					cout << sp;
			}
			cout << endl;
		}
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}