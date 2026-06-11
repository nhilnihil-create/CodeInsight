#include<iostream>
#include<cstdint>
using namespace std;

const int MOD = 1000000007; // 今回使う余り
int main() {
	int n, m, x, y;
	cin >> n >> m;
	
	int64_t xsum = 0, ysum = 0;
	for (int i = 0;i < n;i ++) {
		cin >> x;
		xsum = (xsum + (int64_t)(2 * i + 1 - n) * x) % MOD;
	}
	for (int i = 0;i < m;i ++) {
		cin >> y;
		ysum = (ysum + (int64_t)(2 * i + 1 - m) * y) % MOD;
	}
	cout << xsum * ysum % MOD;
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり
また、コンテスト後に https://31536000.hatenablog.com/ で解説していると思うので、良かったら読んでねー

単に式変形すると解ける
xy独立なのでまずはxについて説明するよ
まず、x方向ではΣ[i=1, n] Σ[j=i + 1, n] (xj - xi)が答え
これだと2重ループだけど、あるkを用いてΣ[k = 1, n] ((k - 1)x_k - (n - k)x_k) = Σ[k = 1, n] ((2k - n - 1)x_k)に等しいと分かるとO(n)
y方向も同様にやって終わり
*/