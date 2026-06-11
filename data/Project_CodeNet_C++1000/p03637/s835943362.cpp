//大文字->小文字 tolower(),逆はtoupper()
//int a = stoi(c); 文字列をintへ
//途中の出力をそのまま残さない
//数値計算 個数以外はdouble
//map<キー,値> p は辞書。p[キー] = 値
//map 全探索
//auto begin = p.begin(), end = p.end();
//for (auto it = begin; it != end; it++) {}
//mapのキー：it->first mapのバリュー：it->second
//絶対値 abs()
//入力は空白で切れる
//大文字判定 isupper(文字) 小文字判定 islower(文字)
//do{}while(next_permutation(ALL(配列)))
//while(N)で回すとき、Nはコピーを作っておく
//小文字に対応する文字コード：S[i] - 'a'
//文字コード→小文字：(char)(数字+'a')
//グラフの距離:隣接行列で扱う
#include <bits/stdc++.h>
#define rep(i,N) for(int i = 0; i < N;i++)
#define ALL(a) (a).begin(),(a).end()
#define ll long long int
using namespace std;

// K進数でのNの桁数
ll dig(ll N,ll K) {
	ll dig = 0;
	while (N) {
		dig++;
		N /= K;
	}
	return dig;
}
// x,yの最大公約数
ll gcd(ll x, ll y) {
	ll r;
	while (x%y) {
		r = x % y;
		x = y;
		y = r;
	}
	return y;
}

//nC2の計算
ll C(ll N) {
	return N * (N - 1) / 2;
}

//円周率
const double PI = 3.14159265358979323846;

int main() {
	ll N; cin >> N;
	vector<ll> a(N); rep(i, N)cin >> a[i];

	ll f = 0, t = 0;
	rep(i, N) {
		if (a[i] % 4 == 0) f++;
		else if (a[i] % 2 == 0)t++;
	}

	ll cnt = 0;
	if (t == 0) cnt = 2 * f + 1;
	else cnt = f * 2 + t;

	if (cnt >= N) cout << "Yes" << endl;
	else cout << "No" << endl;
}