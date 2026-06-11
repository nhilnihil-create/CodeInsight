#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()

//アリとぶつかる=隣のアリに変身

int main() {
	ll N, L, T, W, W1, X, X1, X2 = 0, X3, V = 0, V1 = 0;
	cin >> N >> L >> T;
	ll a, b, c, d;
	a = T % L; b = T / L;
	int j;
	if (a * 2 >= L) {
		j = 1; //ぶつかってくるアリが余計に一周分あり
		c = a * 2 - L;
	}
	else {
		c = a * 2;
		j = 0;
	}
	vector<ll> fir(N);
	vector<ll> las(N);

	cin >> X1 >> W1;
	if (W1 == 1)
		X3 = (X1 + a) % L;
	else
		X3 = (X1 - a + L) % L;
	las[0] = X3;

	for (ll i = 1;i < N;i++) {
		cin >> X >> W;
		//向かってくる奴との距離の差がc未満か否か
		if (W != W1) {
			V++; //ここを忘れていた どうかこの修正でACしてくれ
			if (W == 1) { //自分は反時計回り
				d = L - (X - X1);
				if (d <= c) V1++;
			}
			else {
				d = X - X1;
				if (d < c) V1++;
			}
		}
		if (W == 1) las[i] = (X + a) % L;
		else las[i] = (X + L - a) % L;
	}

	sort(all(las));
	ll col = (b * 2 * V + V * j + V1) % N; //回アリとぶつかる
	if (W1 == 2) col = N - col;
	//最初X1にいたアリはcol個先のアリに変身している
	//つまり、点 X3 にcol番目のアリがいる

	auto it = lower_bound(all(las), X3);

	vector<ll> ans(N);
	for (ll i = 0;i < N;i++) {
		if (it == las.end()) it = las.begin();
		ans[(col + i) % N] = *it;
		it++;
	}
	for (ll i = 0;i < N;i++) {
		cout << ans[i] << endl;
	}
}