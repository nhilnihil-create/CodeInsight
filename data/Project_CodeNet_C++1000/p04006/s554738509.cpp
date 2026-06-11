//N個のボタンがついたダイヤルを回すと考えると分かりやすい。最初, 位置jにあるボタンをボタンjとして、
//位置iではa_i秒でインクを付けることができると読み替える。「ボタンにインクをつける→ダイヤルを回す」を繰り返すイメージをすれば、
//インクをつけられる範囲、回すコストともに固定できる変量として「回す回数」が使えると気付ける。
#include <iostream>
#include <algorithm>
#define int long long
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int n, x;
int a[4000];
int minA[4000];

signed main() {
	int i, j, k;
	
	cin >> n >> x;
	rep(i, n) cin >> a[i];
	rep(i, n) a[i + n] = a[i];
	rep(i, n) minA[i] = 1e+15;
	
	int ans = 1e+15;
	rep(i, n) {
		int cst = 0;
		rep(j, n) {
			minA[j] = min(minA[j], a[j + i]);
			cst += minA[j];
		}
		ans = min(ans, cst + i * x);
	}
	cout << ans << endl;
	return 0;
}