#include"bits/stdc++.h"
using namespace std;
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD (LL)(1e9+7)
/*
//あまりは x より小さい
//y=1...
//x=0...
//この場合 x XOR y が 1... となり x より大きい

//y=1...
//x=1...
//このとき，商は 1 だから，y mod x = y - x

//y - x = x XOR y であればよい

//y=11...
//x=11... ok
//y=11...
//x=10... ok
//y=10...
//x=10... ok

//y=110...
//x=101... ng

//よって
//y=111111...0
//x=11...00000

LL L, R;
int main(){
	cin >> L >> R;
	
}*/

#define int long long
signed main(){
	int i, o, t, j, l, s, z;
	cin >> i >> o >> t >> j >> l >> s >> z;
	int K1 = o + (j/2)*2 + (l/2)*2 + (i/2)*2;
	int K2 = o + (j > 0 && l > 0 && i > 0 ? ((j-1)/2)*2 + ((l-1)/2)*2 + ((i-1)/2)*2 + 3 : 0);
	cout << max(K1, K2) << endl;
}