#define tst(a, b) for (int i = 1; i <= (b); i++) {cout << (a)[i] << " ";} cout << endl;
#define ll long long
#define lf long double
#define ch char
#define F(a) for (int i = 1; i <= (a); i++)
#define For(a, b) for (int (a) = 1; (a) <= (b); (a)++)
#define Rep(a, b, c) for (int (a) = (b); (a) <= (c); (a)++)
#define FD(a) for (int i = (a); i >= 1; i--)
#define ForD(a, b) for (int (a) = (b); (a) >= 1; (a)--)
#define RepD(a, b, c) for (int (a) = (b); (a) >= (c); (a)--)
#define mp(a, b) make_pair((a), (b))
#define pb(a) push_back(a)
#define fi first
#define se second
#define il inline
#define reg register
#define ret return
#define opt operator
#define Mem0(a) memset((a), 0, sizeof(a))
#define MemInf(a) memset((a), 115, sizeof(a))
#define Mem(a, n) memset((a), (n), sizeof(a))
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
inline ll Rd() {
	ll C = getchar();
	ll V = 0;
	ll Sign = 0;
	while (C > '9' || C < '0') {
		Sign |= (C == '-');
		C = getchar();
	}

	while (C <= '9' && C >= '0') {
		V = (V << 1) + (V << 3) + (C ^ '0');
		C = getchar();
	}
	Sign && (V = -V);
	return V;
}


ll A, B, C;
int Table[1000010];

int main()
{
	cin >> A >> B >> C;
	Table[A]++; Table[B]++; Table[C]++;
	if (Table[5] == 2 && Table[7] == 1) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
