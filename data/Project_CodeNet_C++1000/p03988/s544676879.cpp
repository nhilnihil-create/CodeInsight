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

using namespace std;
using ll = long long;

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;

#define REP(i,n) for(int i = 0; i < int(n); i++)
#define FOR(i, m, n) for(int i = int(m);i < int(n);i++)
#define ALL(obj) (obj).begin(),(obj).end()

const ll MOD = (ll)1e9 + 7;
const ll HINF = (ll)1e18;
const ll LINF = (ll)1e9;
const long double PI = 3.1415926535897932384626433;

template<class T> void corner(bool flg, T hoge) { if (flg) { cout << hoge << endl; exit(0); } else return; }
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
	int N; cin >> N;
	V<int> cnt(N, 0);
	REP(i,N) {
		int a; cin >> a;
		cnt[a]++;
	}
	int d;
	for(int i = N-1; 0 < i; --i){
		if(cnt[i]) {
			d = i;
			break;
		}
	}
	
	int flg = 1;
	if (d == 1 && N != 2) flg = 0;
	
	if(d%2){
		for (int i = 0;i < d / 2 + 1; ++i) {
			if (cnt[i]) flg = 0;
		}
		if (cnt[d/2+1] != 2) flg = 0;
		for (int i = d/2 + 2; i <= d; ++i) {
			if (cnt[i] < 2) flg = 0;
		}

		for (int i = d + 1; i < N; ++i) {
			if (cnt[i]) flg = 0;
		}

	}
	else{
		for (int i = 0; i < d/2; ++i) {
			if (cnt[i]) flg = 0;
		}
		if (cnt[d/2] != 1) flg = 0;
		for (int i = d/2 + 1; i <= d; ++i) {
			if (cnt[i] < 2) flg = 0;
		}
		for (int i = d + 1; i < N; ++i) {
			if (cnt[i]) flg = 0;
		}

	}
	cout << (flg ? "Possible" : "Impossible") << endl;
	return 0;
}

