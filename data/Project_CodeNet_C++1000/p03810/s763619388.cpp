#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
	int c;
	while (a != 0) { c = a; a = b%a; b = c; }
	return b;
}
bool f(vector<int> a) {
	if (a[0] == 1) {
		int sum = 0;
		for (int x : a) sum += (x-1) % 2;
		return sum % 2 != 0;
	} else {
		int c_odd = 0, c_even = 0;
		for (int x : a) ++(x % 2 ? c_odd : c_even);
		if (c_even % 2 != 0) {
			return true;
		} else {
			if (c_odd == 0) throw 1;
			if (c_odd >= 2) {
				return false;
			} else {
				auto b = a;
				for (auto& x : b) if (x % 2) {
					--x;
					break;
				}
				int g = b[0];
				for (auto x : b) g = gcd(g, x);
				for (auto& x : b) x /= g;
				return !f(b);
			}
		}
	}
}
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (auto& x : A) cin >> x;
	sort(A.begin(), A.end());
	cout << (f(A) ? "First" : "Second") << endl;
}
/*
1. A_iが1を含む場合

sum(A_i - 1)の偶奇で決まる

2. A_iが1を含まない場合

A_iの最大公約数は1なので、全て偶数ということはない、
すなわち、少なくとも一つ奇数を含む。
よって、gが偶数になることはないので、gは奇数
gは奇数なので、A_iとA_i/gの偶奇は一致

2.1. A_iのなかに偶数が奇数個あるとき

偶数は一つ以上あるので、偶数を選ぶ
奇数が少なくとも2つある状態で相手に渡る
(元からあるやつと、-1してできたやつ)
相手から戻ってきたら、2.2.1.より、偶数が奇数個ある状態になる
よって先手必勝

2.2. A_iのなかに偶数が偶数個あるとき

2.2.1. 奇数が2つ以上のとき

gは奇数になるので、相手に渡す状態は必ずA_iのなかに偶数が奇数個ある状態になる
よって後手必勝

2.2.2. 奇数がちょうど1つのとき

その奇数を選ばないとgは奇数になるので、相手に渡す状態は必ずA_iのなかに偶数が奇数個ある状態になり、後手必勝
その奇数を選ぶとgは偶数になるが、相手に渡す状態は一意に定まる。
*/
