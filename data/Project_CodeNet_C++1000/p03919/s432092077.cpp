#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include "bits/stdc++.h"
#define REP(i,a,b) for(int i=a;i<b;++i)
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define ALL(a) begin(a),end(a)
#define ifnot(a) if(not (a))
#define dump(x)  cerr << #x << " = " << (x) << endl
using namespace std;

// #define int ll
#ifdef _MSC_VER
const bool test = true;
#else 
const bool test = false;
#endif

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
#define INF (1 << 28)
ull mod = (int)1e9 + 7;
//.....................
const int MAX = (int)2e5 + 5;

string s[30][30];

int main() {
	int H, W;
	cin >> H >> W;
	int ansx, ansy;
	rep(i, H) rep(j, W) {
		cin >> s[i][j];
		if (s[i][j] == "snuke") {
			ansy = i;
			ansx = j;
		}
	}
	cout << (char)('A' + ansx);
	cout << ansy + 1 << endl;
	return 0;
}