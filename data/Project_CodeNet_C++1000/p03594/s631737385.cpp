#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

const int M = 4000;
int a[M][M];
char ans[500][500];
string color = "RYGB";

int main() {
	int h, w, d;
	cin >> h >> w >> d;

	int r = d;

	REP(i,M) REP(j,M){
		int x = i / r;
		int y = j / r;
		a[i][j] = 2 * (x%2) + (y%2);
	}

	// REP(i,30){
	// 	REP(j,30){
	// 		cout << a[i][j];
	// 	}
	// 	cout << endl;
	// }

	REP(i,h) REP(j,w){
		ans[i][j] = color[a[2000+i-j][1000+i+j]];
	}

	REP(i,h){
		REP(j,w){
			cout << ans[i][j];
		}
		cout << endl;
	}


    return 0;
}



