#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Zoo {
private:
	int n;
public:
	int* k; // k[i] := 羊なら1,狼なら2,未定なら0
	// コンストラクタ
	Zoo(int n) {
		this->n = n;
		this->k = new int[n];
		for (int i = 0; i < n; ++i)
			k[i] = 0;
	}
	// kを出力する
	void show() {
		for (int i = 0; i < n; ++i)
			cout << (k[i] == 1 ? 'S' : 'W');
		cout << endl;
	}
};

// 動物0,1がそれぞれk0,k1であるとき、
// 残りの動物を順に割り当て、OKかどうか
// 判定する.
bool judge(int n, string s, int k0, int k1) {
	Zoo z(n);
	z.k[0] = k0;
	z.k[1] = k1;
	for (int i = 2; i < n; ++i) {
		// 動物i-1の発言に基づいて動物iを決定する.
		if (z.k[i - 1] == 1 && s[i - 1] == 'o') {
			z.k[i] = z.k[i - 2];
		}
		else if (z.k[i - 1] == 1 && s[i - 1] == 'x') {
			z.k[i] = z.k[i - 2] == 1 ? 2 : 1;
		}
		else if (s[i - 1] == 'o') {
			z.k[i] = z.k[i - 2] == 1 ? 2 : 1;
		}
		else
			z.k[i] = z.k[i - 2];
	}
	bool f = true; // 割り当てが正しいかのフラグ
	// 動物n-1の発言を検証する
	if (z.k[n - 1] == 1) { // 羊の場合
		if (s[n - 1] == 'o')
			f = f && z.k[n - 2] == z.k[0];
		else
			f = f && z.k[n - 2] != z.k[0];
	}
	else { // 狼の場合
		if (s[n - 1] == 'o')
			f = f && z.k[n - 2] != z.k[0];
		else
			f = f && z.k[n - 2] == z.k[0];
	}
	// 動物0の発言を検証する
	if (z.k[0] == 1) { // 羊の場合
		if (s[0] == 'o')
			f = f && z.k[n - 1] == z.k[1];
		else
			f = f && z.k[n - 1] != z.k[1];
	}
	else { // 狼の場合
		if (s[0] == 'o')
			f = f && z.k[n - 1] != z.k[1];
		else
			f = f && z.k[n - 1] == z.k[1];
	}
	// 割り当てが正しくないならfalse
	if (!f) return false;
	// 正しいなら出力してtrue
	z.show();
	return true;
}

signed main() {
	int n; cin >> n;
	string s; cin >> s;

	for (int i = 0; i < 4; ++i) {
		if (judge(n, s, i / 2 + 1, (i & 1) + 1)) return 0;
	}

	cout << "-1\n";

	return 0;
}