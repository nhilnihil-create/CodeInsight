#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <climits>
#include <cassert>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> vi;
typedef vector<string> VS;
typedef pair<int, int> pii;
typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

const double EPS = 1e-9;
const double PI  = acos(-1.0);
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};

#define CLR(a) memset((a), 0 ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

vi sub(int p, int q)
{
	vi res(p);
	int t = p / q + 1;

	rep(i, p) {
		if (i % q == q-1) {
			res[i] = -(t*(q-1))-1;
		} else {
			res[i] = t;
		}
	}
	return res;
}

vector<vi> solve(int a, int b, int c, int d)
{
	vector<vi> res;
	vi t = sub(c, d);
	rep(i, a) res.pb(t);
	return res;
}

void out(vector<vi> res)
{
	puts("Yes");
	rep(i, res.size()) {
		rep(j, res[i].size()) {
			printf("%d%c", res[i][j], j + 1 == (int)res[i].size() ? '\n' : ' ');
		}
	}
}

int main() {
	int H, W, h, w;
	cin >> H >> W >> h >> w;

	if (W % w != 0) {
		auto t = solve(H, h, W, w);
		out(t);
	} else if (H % h != 0) {
		auto t = solve(W, w, H, h);
		vector<vi> res;
		rep(i, H) {
			vi vec;
			rep(j, W) {
				vec.pb(t[j][i]);
			}
			res.pb(vec);
		}
		out(res);
	} else {
		puts("No");
	}

	return 0;
}