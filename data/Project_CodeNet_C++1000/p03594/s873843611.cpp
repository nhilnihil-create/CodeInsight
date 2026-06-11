#include<map>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
typedef long long ll;
using namespace std;

ll grid[505][505];
char xxx[5] = { 't','R','G','B','Y' };

struct point{
	ll x; ll y;
};

point shif(point t) {
	return { t.x + t.y, t.x - t.y };
}

int main(){
	ll h, w,d;
	cin >> h >> w >> d;
	ll bignum = 100000000 * d;
	REP(i, 0, h - 1) {
		REP(j, 0, w - 1) {
			point t = shif({ i,j });
			ll s1 = ((t.x + bignum) / d) % 2;
			ll s2 = (t.y + bignum) / d % 2;
			if (s1 == 0 && s2 == 0) {
				grid[i][j] = 1;
			}
			else if (s1 == 0 && s2 == 1) {
				grid[i][j] = 2;
			}
			else if (s1 == 1 && s2 == 0) {
				grid[i][j] = 3;
			}
			else {
				grid[i][j] = 4;
			}
		}
	}
	REP(i, 0, h - 1) {
		REP(j, 0, w - 1) {
			cout << xxx[grid[i][j]];
		}
		cout << endl;
	}
}