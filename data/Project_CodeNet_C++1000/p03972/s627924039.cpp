#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

typedef long long ll;
typedef pair<bool, int> P;

int W, H;
ll costw[100000 + 10], costh[100000 + 10];
pair<ll, P> sortlist[100000 * 2 + 10];

int main() {
	cin >> W >> H;
	for (int i = 0; i < W; i++) {
		cin >> costw[i];
		sortlist[i] = make_pair(costw[i], P(i, 0));
	}
	for (int i = 0; i < H; i++) {
		cin >> costh[i];
		sortlist[i + W] = make_pair(costh[i], P(i, 1));
	}
	sort(sortlist, sortlist + W + H);

	ll ans = 0;
	int cnth = 0, cntw = 0;
	for (int i = 0; i < H + W; i++) {
		if (sortlist[i].second.second == 0) {
			ans += sortlist[i].first * (H + 1 - cnth);
			cntw++;
		}
		else {
			ans += sortlist[i].first * (W + 1 - cntw);
			cnth++;
		}
	}
	cout << ans << endl;
	return 0;
}