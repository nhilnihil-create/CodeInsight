#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
const ll MOD = 1000000007;

int main(){
	int H, W;
	cin >> W >> H;
	vector<ll> P(W), Q(H);
	for (int i = 0;i < W;i++) {
		cin >> P[i];
	}
	for (int i = 0;i < H;i++) {
		cin >> Q[i];
	}
	P.push_back(MOD);
	Q.push_back(MOD);

	//よくわかるクラスカル法 以上！w
	sort(all(P));
	sort(all(Q));
	ll h = H + 1, w = W + 1, hi = 0, wi = 0;
	ll ans = 0;
	while (hi < H || wi < W) {
		if (P[wi] < Q[hi]) {
			ans += P[wi] * h;
			w--;
			wi++;
		}
		else {
			ans += Q[hi] * w;
			h--;
			hi++;
		}
	}
	cout << ans << endl;
}