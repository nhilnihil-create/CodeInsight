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

template<class T> void corner(bool flg, T hoge) {
	if (flg) {
		cout << hoge << endl;
		exit(0);
	}
	else return;
}

template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {
	o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;
}

template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {
	o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}

template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {
	o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;
}

template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {
	o << "{" << obj.first << ", " << obj.second << "}"; return o;
}

template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {
	o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}

void print(void) {
	cout << endl;
}

template <class Head> void print(Head&& head) {
	cout << head;
	print();
}

template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {
	cout << head << " ";
	print(forward<Tail>(tail)...);
}

void YN(bool flg) {
	cout << ((flg) ? "YES" : "NO") << endl;
}

void Yn(bool flg) {
	cout << ((flg) ? "Yes" : "No") << endl;
}

void yn(bool flg) {
	cout << ((flg) ? "yes" : "no") << endl;
}

int main() {
	ll N, K; cin >> N >> K;
	V<ll> a(N); REP(i, N) cin >> a[i];
	sort(ALL(a));
	corner(accumulate(ALL(a), 0LL) < K, N);
	int ok = N-1, ng = -1, md;
	while(ok-ng>1){
		md = (ok + ng) / 2;
		
		if(a[md]>=K){
			ok = md;
			continue;
		}

		V<ll> b(N,0);
		int idx = 1;
		REP(i, N) if (i != md) b[idx++] = a[i];

		V<V<int>> dp(N, V<int>(K, 0));
		dp[0][0] = 1;
		FOR(i,1,N){
			REP(j,K){
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				if(j+b[i]<K)dp[i][j+b[i]] = max(dp[i][j+b[i]], dp[i-1][j]);
			}
		}
		bool flg = false;
		FOR(j, K - a[md], K) if (dp[N-1][j]) flg = true;
		((flg) ? ok : ng) = md;
	}
	cout << ok << endl;
	
	return 0;
}

