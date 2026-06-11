#include <bits/stdc++.h>
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
const ll HINF = (ll)1e18;
const ll LINF = (ll)1e15;
const long double PI = 3.1415926535897932384626433;

template<typename T> vector<T> make_v(size_t N,T init){return vector<T>(N,init);}
template<typename... T> auto make_v(size_t N,T... t){return vector<decltype(make_v(t...))>(N,make_v(t...));}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
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

template<class T> class SegmentTree {
	size_t length;               //セグメント木の最下段の要素の数(vectorの要素の数を超える2べきの数)
	T init;                      //各ノードの初期値
	vector<T> node;              //ノード
	function<T(T,T)> funcNode;
	function<T(T,T)> funcMerge;

public:
	//vectorで初期化
	SegmentTree(const vector<T> & vec, const T init, function<T(T,T)> funcNode, function<T(T,T)> funcMerge) : init(init), funcNode(funcNode), funcMerge(funcMerge) {
		for (length = 1; length < vec.size(); length *= 2);
		node.resize(2 * length, init);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
		for (int i = length - 1; i >= 0; --i) node[i] = funcNode(node[(i<<1)+0],node[(i<<1)+1]);
	}
 
	//lengthだけで初期化
	SegmentTree(const size_t num, const T init, function<T(T,T)> funcNode, function<T(T,T)> funcMerge) : init(init), funcNode(funcNode), funcMerge(funcMerge) {
		for (length = 1; length < num; length *= 2);
		node.resize(2 * length, init);
	}
	
	//idx : 0-indexed
	void update(size_t idx, const T var) {
		if(idx < 0 || length <= idx) return;
		idx += length;
		node[idx] = funcMerge(node[idx],var);
		while(idx >>= 1) node[idx] = funcNode(node[(idx<<1)+0],node[(idx<<1)+1]);
	}

	//[l,r)
	T get(int l, int r) {
		if (l < 0 || length <= l || r < 0 || length < r) return init;
		T vl = init, vr = init;
		for(l += length, r += length; l < r; l >>=1, r >>=1) {
			if(l&1) vl = funcNode(vl,node[l++]);
			if(r&1) vr = funcNode(vr,node[--r]);
		}
		return funcNode(vl,vr);
	}
 
	void print(){
		cout << "{ " << get(0,1);
		for(int i = 1; i < length; ++i) cout << ", " << get(i,i+1);
		cout << " }" << endl;

		for(int i = 1,j = 1; i < 2*length; ++i) {
			cout << node[i] << " ";
			if(i==((1<<j)-1) && ++j) cout << endl;
		}
	}

};

//GCD
//verify https://atcoder.jp/contests/abc125/tasks/abc125_c

//SUM
//verify https://atcoder.jp/contests/arc077/tasks/arc077_c

//MIN
//verify https://atcoder.jp/contests/bitflyer2018-final-open/tasks/bitflyer2018_final_c

//MAX
//verify https://atcoder.jp/contests/wupc2019/tasks/wupc2019_d

int main() {
	ll n,m; cin >> n >> m;
	V<ll> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	function<ll(ll,ll)> funcNode =  [&](ll a,ll b){return a+b;};
	function<ll(ll,ll)> funcMerge = [&](ll a,ll b){return a+b;};
	SegmentTree<ll> Seg1(2*m+2,0,funcNode,funcMerge),Seg2(2*m+2,0,funcNode,funcMerge),Seg3(2*m+2,0,funcNode,funcMerge),Seg4(2*m+2,0,funcNode,funcMerge);
 
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
		ll x = Seg1.get(0,key+m);
		ll y = Seg3.get(0,key);
		ll cnt = sum - (Seg2.get(key+m,2*m+2)+(key-1)*x + Seg4.get(key-m + m,2*m+2)+(key-m -1)*y);
 
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
