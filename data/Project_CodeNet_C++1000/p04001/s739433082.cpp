#include "bits/stdc++.h"
using namespace std;

int main( ) {
	cin.tie(0); ios::sync_with_stdio(false);
	string S; cin >> S;
	int Lbit = S.size()-1;
	S = string(10 - S.size( ), '0') + S;
	int64_t total = 0;
	for (int i = 0; i < (1 << Lbit); ++i) {
		bitset<9> b(i);
		int64_t sum = 0;
		int64_t pool = 0;
		for (int k = 0; k < 9; ++k) {
			int64_t self = int(S[k] - '0');
			if (b.test(8-k)) { // test ビットが1なら真
				//プールも自分もフラッシュ
				sum += (pool + self);
				pool = 0;
			} else {
				//自分をプールにいれて，１０倍する
				pool += self;
				pool *= 10;
			}
		}
		//最後の桁の処理 	//プールをフラッシュして，自分をsumに足す
		sum += (pool + int(S[9] - '0'));
		total += sum;
	}
	cout << total << endl;
}