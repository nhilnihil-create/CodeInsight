#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define REP(i,n) for(long long i = 0; i < (n); i++)
#define FOR(i, m, n) for(long long i = (m);i < (n); ++i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SPEED cin.tie(0);ios::sync_with_stdio(false);

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQR = priority_queue<T,vector<T>,greater<T>>;

constexpr long long MOD = (long long)1e9 + 7;
constexpr long long MOD2 = 998244353;
constexpr long long HIGHINF = (long long)1e18;
constexpr long long LOWINF = (long long)1e15;
constexpr long double PI = 3.1415926535897932384626433;

template <class T> vector<T> make_v(size_t N,T init){return vector<T>(N,init);}
template <class... T> auto make_v(size_t N,T... t){return vector<decltype(make_v(t...))>(N,make_v(t...));}
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
template <class T> void chmax(T& a, const T b){a=max(a,b);}
template <class T> void chmin(T& a, const T b){a=min(a,b);}
void YN(bool flg) {cout << (flg ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << (flg ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << (flg ? "yes" : "no") << endl;}



template<class T> class LazySegmentTree {
	size_t length;                  //セグメント木の最下段の要素の数(vectorの要素の数を超える2べきの数)
	size_t height;                  //セグメント木の高さ 
	T unitNode;                     //nodeの単位元
	T unitLazy;                     //lazyの単位元
	vector<T> node;                 //node
	vector<T> lazy;                 //lazy
	vector<int> width;              //width
	function<T(T,T)> funcNode;      //node同士の演算
	function<T(T,T)> funcLazy;      //lazy同士の演算
	function<T(T,T,int)> funcMerge; //nodeとlazyの演算

public:
	//vectorで初期化
	LazySegmentTree(const vector<T> & vec, const T unitNode, const T unitLazy, function<T(T,T)> funcNode, function<T(T,T)> funcLazy,function<T(T,T,int)> funcMerge)
	 : unitNode(unitNode), unitLazy(unitLazy), funcNode(funcNode),funcLazy(funcLazy),funcMerge(funcMerge) {
		for (length = 1,height = 0; length < vec.size(); length *= 2, height++);
		node.resize(2 * length, unitNode);
		lazy.resize(2 * length, unitLazy);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
		for (int i = length - 1; i >= 0; --i) node[i] = funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		width.resize(2 * length, 0);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}

	//同じinitで初期化
	LazySegmentTree(const size_t num, const T unitNode, const T unitLazy, const T init, function<T(T,T)> funcNode, function<T(T,T)> funcLazy,function<T(T,T,int)> funcMerge)
	 : unitNode(unitNode), unitLazy(unitLazy), funcNode(funcNode),funcLazy(funcLazy),funcMerge(funcMerge) {
		for (length = 1,height = 0; length < num; length *= 2, height++);
		node.resize(2 * length, unitNode);
		lazy.resize(2 * length, unitLazy);
		for (int i = 0; i < num; ++i) node[i + length] = init;
		for (int i = length - 1; i >= 0; --i) node[i] = funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		width.resize(2 * length, 0);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}
 
	//unitだけで初期化
	LazySegmentTree(const size_t num, const T unitNode, const T unitLazy, function<T(T,T)> funcNode, function<T(T,T)> funcLazy,function<T(T,T,int)> funcMerge)
	: unitNode(unitNode), unitLazy(unitLazy), funcNode(funcNode),funcLazy(funcLazy),funcMerge(funcMerge) {
		for (length = 1,height = 0; length < num; length *= 2, height++);
		node.resize(2 * length, unitNode);
		lazy.resize(2 * length, unitLazy);
		width.resize(2 * length, 0);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}


	void propagate(int k) {
		if(lazy[k] == unitLazy) return;
		node[k] = funcMerge(node[k],lazy[k],width[k]);
		if(k < length) lazy[2*k+0] = funcLazy(lazy[2*k+0],lazy[k]);
		if(k < length) lazy[2*k+1] = funcLazy(lazy[2*k+1],lazy[k]);
		lazy[k] = unitLazy;
    }


	//idx : 0-indexed
    void update(int a, int b, T x) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) lazy[l] = funcLazy(lazy[l],x), propagate(l),l++;
			if(r&1) --r,lazy[r] = funcLazy(lazy[r],x), propagate(r);
		}
		l = a + length, r = b + length - 1;
		while ((l>>=1),(r>>=1),l) {
			if(lazy[l] == unitLazy) node[l] = funcNode(funcMerge(node[(l<<1)+0],lazy[(l<<1)+0],width[(l<<1)+0]),funcMerge(node[(l<<1)+1],lazy[(l<<1)+1],width[(l<<1)+1]));
			if(lazy[r] == unitLazy) node[r] = funcNode(funcMerge(node[(r<<1)+0],lazy[(r<<1)+0],width[(r<<1)+0]),funcMerge(node[(r<<1)+1],lazy[(r<<1)+1],width[(r<<1)+1]));
		}
    }

	//[l,r)
	T get(int a, int b) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		T vl = unitNode, vr = unitNode;
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) vl = funcNode(vl,funcMerge(node[l],lazy[l],width[l])),l++;
			if(r&1) r--,vr = funcNode(vr,funcMerge(node[r],lazy[r],width[r]));
		}
		return funcNode(vl,vr);
	}

	void print(){
		cout << "height" << " " << height << endl;
		cout << "node" << endl;
		for(int i = 1,j = 1; i < 2*length; ++i) {
			cout << node[i] << " ";
			if(i==((1<<j)-1) && ++j) cout << endl;
		}
		cout << "lazy" << endl;
		for(int i = 1,j = 1; i < 2*length; ++i) {
			cout << lazy[i] << " ";
			if(i==((1<<j)-1) && ++j) cout << endl;
		}
		// cout << "width" << endl;
		// for(int i = 1,j = 1; i < 2*length; ++i) {
		// 	cout << width[i] << " ";
		// 	if(i==((1<<j)-1) && ++j) cout << endl;
		// }
		cout << "vector" << endl;
		cout << "{ " << get(0,1);
		for(int i = 1; i < length; ++i) cout << ", " << get(i,i+1);
		cout << " }" << endl;
	}

};

//RUQ + RMQ
//verify https://atcoder.jp/contests/nikkei2019-final/tasks/nikkei2019_final_d

// 区間加算 + 区間最小
// function<ll(ll,ll)> funcNode  = [&](ll l,ll r){return min(l,r);};
// function<ll(ll,ll)> funcLazy  = [&](ll l,ll r){return l+r;};
// function<ll(ll,ll,int)> funcMerge = [&](ll l,ll r,int c){return l+r;};
// LazySegmentTree<ll> Seg(N,inf,0,0,funcNode,funcLazy,funcMerge);

// 区間加算 + 区間総和
// function<ll(ll,ll)> funcNode  = [&](ll l,ll r){return l+r;};
// function<ll(ll,ll)> funcLazy  = [&](ll l,ll r){return l+r;};
// function<ll(ll,ll,int)> funcMerge = [&](ll l,ll r,int c){return l+r*c;};
// LazySegmentTree<ll> Seg(N,0,0,funcNode,funcLazy,funcMerge);

// 区間更新 + 区間総和
// function<ll(ll,ll)> funcNode  = [&](ll l,ll r){return l+r;};
// function<ll(ll,ll)> funcLazy  = [&](ll l,ll r){return r;};
// function<ll(ll,ll,int)> funcMerge = [&](ll l,ll r,int c){return r!=-2000?r*c:l;};
// LazySegmentTree<ll> Seg(N,0,-2000,0,funcNode,funcLazy,funcMerge);

// 区間更新 + 区間最大
// function<ll(ll,ll)> funcNode  = [&](ll l,ll r){return max(l,r);};
// function<ll(ll,ll)> funcLazy  = [&](ll l,ll r){return r;};
// function<ll(ll,ll,int)> funcMerge = [&](ll l,ll r,int c){return r!=0?r:l;};
// LazySegmentTree<ll> Seg(N+2,0,0,funcNode,funcLazy,funcMerge);


int main() {

	int N,M; cin >> N >> M;

	function<ll(ll,ll)> funcNode  = [&](ll l,ll r){return l+r;};
	function<ll(ll,ll)> funcLazy  = [&](ll l,ll r){return l+r;};
	function<ll(ll,ll,int)> funcMerge = [&](ll l,ll r,int c){return l+r*c;};
	LazySegmentTree<ll> Seg(M+2,0,0,funcNode,funcLazy,funcMerge);
	V<int> l(N),r(N),ans(M+1,0);
	V<P<int,int>> ord(N);
 
	for(int i = 0; i < N; ++i) {
		cin >> l[i]  >> r[i];
		ord[i] = {r[i]-l[i]+1,i};
	}
	sort(ALL(ord));
	int n = 0;
	for(int i = 1; i <= M; ++i){
		while(1){
			if(n >= N || i < ord[n].first) break;
			int idx = ord[n].second;
			Seg.update(l[idx],r[idx]+1,1);
			++n;
		}
		ans[i] += N - n;
		for(int j = i; j <= M; j += i) ans[i] += Seg.get(j,j+1);
		
	}
	for(int i  = 1; i <= M; ++i) cout << ans[i] << endl;		
	return 0;
}
