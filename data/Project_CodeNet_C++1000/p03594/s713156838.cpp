#include <iostream>
#include <fstream>
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string> 
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;

#define REP(i,n) for(long long i = 0; i < (n); i++)
#define FOR(i, m, n) for(long long i = (m);i < (n); ++i)
#define ALL(obj) (obj).begin(),(obj).end()

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;

const ll MOD = (ll)1e9 + 7;
const ll MOD2 = 998244353;
const ll LLINF = (ll)1e18;
const ll INTINF = (ll)1e9;
const long double PI = 3.1415926535897932384626433;

template <class T> void corner(bool flg, T hoge) { if (flg) { cout << hoge << endl; exit(0); } }
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) { o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o; }
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) { o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o; }
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) { o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o; }
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) { o << "{" << obj.first << ", " << obj.second << "}"; return o; }
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) { o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o; }
void print(void) { cout << endl; }
template <class Head> void print(Head&& head) { cout << head; print(); }
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) { cout << head << " "; print(forward<Tail>(tail)...); }
template <class T> void chmax(T& a, const T b) { a = max<T>(a, b); }
template <class T> void chmin(T& a, const T b) { a = min<T>(a, b); }
void YN(bool flg) { cout << ((flg) ? "YES" : "NO") << endl; }
void Yn(bool flg) { cout << ((flg) ? "Yes" : "No") << endl; }
void yn(bool flg) { cout << ((flg) ? "yes" : "no") << endl; }

int main() {
	int H, W, d; cin >> H >> W >> d;
	V<V<int>> a(H, V<int>(W, -1));
	if (d % 2) {
		for (int i = 0; i < 2 * max(H, W); ++i) {
			for (int j = 0; j < max(H, W); ++j) {
				if (0 <= j && j < H && 0 <= i - j&&i - j<W) a[j][i - j] = i % 4;
			}
		}
	}
	else {
		for (int i = 0, k = 0; i < 2 * max(H, W); i += 2, (k += 1) %= d) {
			for (int j = 0, l = k; j < max(H, W); ++j, (l += d - 1) %= d) {
				if (0 <= j && j < H && 0 <= i - j&&i - j<W) a[j][i - j] = (l<(d / 2)) + 2 * (k<(d / 2));
			}
		}
		for (int i = 1, k = 0; i < 2 * max(H, W); i += 2, (k += 1) %= d) {
			for (int j = 0, l = k; j < max(H, W); ++j, (l += d - 1) %= d) {
				if (0 <= j && j < H && 0 <= i - j&&i - j<W) a[j][i - j] = (l<(d / 2)) + 2 * (k<(d / 2));
			}
		}

	}
	string S = "RYGB";
	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			cout << S[a[i][j]];
		}
		cout << endl;
	}
	return 0;
}

