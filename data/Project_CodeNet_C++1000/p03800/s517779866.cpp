#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;
#define TOSTRING(x) #x
#define SZ(x) (int)(x).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPR(i,n) for(int i=(n)-1;i>=0;i--)
#define ALL(s) (s).begin(), (s).end()
#define so(V) sort(ALL(V))
#define rev(V) reverse(ALL(V))
#define uni(v) v.erase( unique(ALL(v)) , v.end());
#define PAU system("pause")

typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = (1 << 28);
const ll LINF = 1e18;
const double PI = acos(-1);
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }

int N;
string S;

bool solve(vb &isS) {
	FOR(i, 2, N + 1) {
		if (isS[i - 1]) {
			if (S[i - 1] == 'o') {
				isS[i] = isS[i - 2];
			}
			else isS[i] = !isS[i - 2];
		}
		else {
			if (S[i - 1]  == 'o')isS[i] = !isS[i - 2];
			else isS[i] = isS[i - 2];
		}
	}
	if (isS[0] == isS[N]) {
		REP(i, N)if ((isS[(i + N - 1) % N] ^ isS[(i + 1) % N]) != ((S[i] == 'o') ^ (isS[i])))
			return false;
		return true;
	}
	return false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N;
	cin >> S;
	vb isS(N + 1);
	vvb loop({ {true,true},{true,false},{false,true},{false,false} });
	REP(i, 4) {
		isS[0] = loop[i][0];
		isS[1] = loop[i][1];
		if (solve(isS)) {
			REP(i, N) {
				cout << (isS[i]?'S':'W');
			}
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
