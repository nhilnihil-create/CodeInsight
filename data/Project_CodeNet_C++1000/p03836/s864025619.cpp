#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

string solve(int sx, int sy, int tx, int ty) {
	string res = "";
	int w = tx - sx;
	int h = ty - sy;
	rep(i,w) res += 'R';
	rep(i,h) res += 'U';
	rep(i,w) res += 'L';
	rep(i,h) res += 'D';
	res += 'D';
	rep(i,w+1) res += 'R';
	rep(i,h+1) res += 'U';
	res += 'L'; 	
	res += 'U';
	rep(i,w+1) res += 'L';
	rep(i,h+1) res += 'D';
	res += 'R';
	return res;
}

int main() {
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	cout << solve(sx, sy, tx, ty) << endl;
}