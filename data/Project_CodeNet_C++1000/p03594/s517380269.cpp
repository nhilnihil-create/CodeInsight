#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

const int MAX_N = 1000000;
const int INFTY = (1 << 21); // 2097152
// const ll INFTY = (1LL << 60);
const ll MD = 1000000007LL;
// fprintf(stderr, "%d %lld \n", x, xll);


int H, W, D;
int M[500][500];
int T[2000][2000];

int main() {
	cin >> H >> W >> D;

	// initialize
	rep(y, 2000) rep(x, 2000) T[y][x] = -1;

	int L;
	if(D % 2 == 1){
		L = 2;
		T[0][0] = 0;
		T[0][1] = 1;
		T[1][0] = 1;
		T[1][1] = 0;
	}
	else{

		L = D * 2;
		vector<int> vs = {0, 1, 2, 3, 1, 0, 3, 2};
		vector<int> xs = {0, 2, 1, 3, 0, 2, 1, 3};
		vector<int> ys = {0, 0, 1, 1, 2, 2, 3, 3};

		rep(i, 8){
			int v = vs[i];
			int x = xs[i] * D / 2;
			int y = ys[i] * D / 2;

			int mnx = 0;
			int mxx = 0;
			for(int yy = 0; yy <= D-2; yy++){
				for(int xx = mnx; xx <= mxx; xx += 2){
					int yyy = (y + yy + L) % L;
					int xxx = (x + xx + L) % L;
					// fprintf(stderr, "%d [%d][%d] %d %d\n", v, yyy, xxx, y, x);
					T[yyy][xxx] = v;
				}
				if(yy < (D-2)/2){
					mnx--;
					mxx++;
				}
				else{
					mnx++;
					mxx--;
				}
			}
		}

		// painting odd
		rep(y, L) rep(x, L){
			int xx = (x - 1 + L) % L;
			int yy = y;
			if(T[y][x] == -1) T[y][x] = T[yy][xx];
		}
	}

	// output;
	rep(y, H) rep(x, W){
		M[y][x] = T[y % L][x % L];
	}

	vector<char> cs = {'R','Y','G','B'};

	// debug
	/*
	rep(y, L){
		rep(x, L) {
			int col = T[y][x];
			cerr << col; // cs[col];
		}
		cerr << endl;
	}
	*/

	rep(y, H){
		rep(x, W) {
			int col = M[y][x];
			cout << cs[col];
		}
		cout << endl;
	}
}