#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
#define MOD 1000000007

ll seg[2097152];

void eval(int x) {
	if (x > 1048575)return;
	seg[x * 2] += seg[x];seg[x * 2] %= MOD;
	seg[x * 2 + 1] += seg[x];seg[x * 2 + 1] %= MOD;
	seg[x] = 0;
	return;
}

void upd(int s, int t, ll v, int k = 1, int l = 0, int r = 1048575) {
	if (t < l || r < s)return;
	if (s <= l && r <= t) {
		seg[k] += v;
		seg[k] %= MOD;
		return;
	}
	eval(k);
	//cout << s << " " << t << " " << v << " " << k << " " << l << " " << r << endl;
	upd(s, t, v, k * 2, l, (l + r) / 2);
	upd(s, t, v, k * 2 + 1, (l + r) / 2 + 1, r);
}

ll get(ll X) {
	X += 1048576;
	ll ans = seg[X];
	while (X) {
		X /= 2;
		ans += seg[X];
		ans %= MOD;
		eval(X);
	}
	return ans;
}

int main() {
	for (int i = 0;i < (1 << 21);i++)seg[i] = 0;
	ll N;
	cin >> N;
	upd(1, 1, 1);
	//Nまで更新したい

	//1~Nまで…[1…N]を選べる。それぞれ選んだ時、i+1,[i+3…i+N+1]が次に選択可能なマス→セグ木で1加算
	//ただし更新されるはずのN+1からi+N+1までは選択が不可能→この分はセグ木ではなくansに保存 i+1個

	//N-2,N-1…1を選ぶと次を選べる それ以外はセグ木に達してしまうのでアウト Nをかける
	//N…単純に(そこの数)×Nをansに加算

	ll ans = 0;
	for (ll i = 1;i <= N;i++) {
		if (i > N - 3) {
			if (i == N)ans += N * get(i);//1からNのどれかを選ぶので
			else {
				//そこに1を入れる時
				upd(i + 1, i + 1, get(i));
				//1を入れない時
				//1以外を入れる…N-1通り、次のマスに何かを入れる…N通り
				ans += ((N - 1) * N % MOD) * get(i) % MOD;
				ans %= MOD;
			}
		}
		else {
			//そこに1を入れるとき
			upd(i + 1, i + 1, get(i));
			//1を入れない時
			//次のマスに1を入れる時
			upd(i + 3, N, get(i));
			ans += (i + 1) * get(i) % MOD;
			//1を入れない時
			ans += ((N - 1) * (N - 1) % MOD) * get(i) % MOD;
		}
		ans %= MOD;
	}
	cout << ans << endl;
}