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

template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
template <class T> void chmax(T& a, const T b){a=max<T>(a,b);}
template <class T> void chmin(T& a, const T b){a=min<T>(a,b);}
void YN(bool flg) {cout << ((flg) ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << ((flg) ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << ((flg) ? "yes" : "no") << endl;}


template<class T> class SegmentTreePointAddRangeSum {
	size_t length; //セグメント木の最下段の要素の数(vectorの要素の数を超える2べきの数)
	T init;         //各ノードの初期値
	vector<T> node; //ノード

public:
	//vectorで初期化
	SegmentTreePointAddRangeSum(const vector<T> & ar, const T init) : init(init) {
		for (length = 1; length < ar.size(); length *= 2);
		node.resize(2 * length - 1, init);
		for (int i = 0; i < ar.size(); ++i) node[i + length - 1] = ar[i];
		for (int i = length - 2; i >= 0; --i) node[i] = node[2 * i + 1]+node[2 * i + 2];
	}
 
	//lengthだけで初期化
	SegmentTreePointAddRangeSum(const size_t num, const T init) : init(init) {
		for (length = 1; length < num; length *= 2);
		node.resize(2 * length - 1, init);
	}
	
	void update(size_t idx, const T var) {
		if(idx < 0 || length <= idx) return;
		idx += (length - 1);
		node[idx] += var;
		while (idx) {
			idx = ((idx - 1) >> 1);
			node[idx] = node[(idx<<1) + 1]+node[(idx<<1) + 2];
		}
	}
 
	T getvar(const int a, const int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = length;
		if (r <= a || b <= l) return init;
		if (a <= l && r <= b) return node[k];
		T vl = getvar(a, b, 2 * k + 1, l, (l + r) / 2);
		T vr = getvar(a, b, 2 * k + 2, (l + r) / 2, r);
		return vl+vr;
	}
 
	void print(){
		cout << "{ " << getvar(0,1);
		for(int i = 1; i < length; ++i) cout << ", " << getvar(i,i+1);
		cout << " }" << endl;

		for(int i = 0,j = 1; i < 2*length-1; ++i) {
			if(i==((1<<j)-1) && ++j) cout << endl;
			cout << node[i] << " ";
		}
	}

};


int main() {
	ll n,m; cin >> n >> m;
	V<ll> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	
	SegmentTreePointAddRangeSum<ll> Seg1(2*m+2,0),Seg2(2*m+2,0),Seg3(2*m+2,0),Seg4(2*m+2,0);

	for(int i = 0; i < n-1; ++i) Seg1.update(a[i] - (a[i+1]>a[i]?0:m) + m,1);
	for(int i = 0; i < n-1; ++i) Seg2.update(a[i] - (a[i+1]>a[i]?0:m) + m,a[i] - (a[i+1]>a[i]?0:m));
	
	ll sum = 0;
	for(int i = 1; i < n; ++i) sum += a[i];
	ll ans = sum;
	for(int i = 0; i < n-1; ++i) ans -= (a[i] - (a[i+1]>a[i]?0:m) );
	
	V<P<ll,int>> ord;
	for(int i = 1; i < n; ++i) ord.push_back({a[i],i});

	sort(ALL(ord));
	for(auto e:ord){
		ll key = e.first;
		int idx = e.second;
		ll x = Seg1.getvar(0,key+m);
		ll y = Seg3.getvar(0,key);
		ll cnt = sum - (Seg2.getvar(key+m,2*m+2)+(key-1)*x + Seg4.getvar(key-m + m,2*m+2)+(key-m -1)*y);

		chmin(ans,cnt);
		ll z = a[idx-1] - (a[idx]>a[idx-1]?0:m);
		Seg1.update(z + m,-1);
		Seg2.update(z + m,-z);
		Seg3.update(z + m, 1);
		Seg4.update(z + m, z);

	}
	cout << ans << endl;
	return 0;
}
