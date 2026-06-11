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

template<class T> class Lazy_Segment_Tree_Range_Sum_Query {
 	size_t N, M;
	T ini;
	vector<T> node,lazy;

public:
    Lazy_Segment_Tree_Range_Sum_Query(const vector<T> & ar, const T ini) : M(ar.size()),ini(ini){
        for (N = 1; N < M; N *= 2);
        node.resize(2 * N - 1, ini);
        lazy.resize(2 * N - 1, ini);
		for (int i = 0; i<M; ++i) node[i + N - 1] = ar[i];
		for (int i = N - 2; i >= 0; --i) node[i] = node[2 * i + 1]+node[2 * i + 2];
    }

	Lazy_Segment_Tree_Range_Sum_Query(const size_t M, const T ini) : M(M),ini(ini){
        for (N = 1; N < M; N *= 2);
        node.resize(2 * N - 1, ini);
        lazy.resize(2 * N - 1, ini);
    }

    void eval(int k, int l, int r) {
		node[k] += lazy[k];
		if(r - l > 1) lazy[2*k+1] += lazy[k] / 2;
		if(r - l > 1) lazy[2*k+2] += lazy[k] / 2;
		lazy[k] = ini;
    }

    void update(int a, int b, T x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = N;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else {
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    T getvar(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = N;
        eval(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        T vl = getvar(a, b, 2*k+1, l, (l+r)/2);
        T vr = getvar(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }

	T operator[](size_t i) {
		return getvar(i, i + 1);
	}

	T operator[](pair<size_t, size_t> p) {
		return getvar(p.first, p.second);
	}

	void print(){
		cout << "{ " << getvar(0,1);
		for(int i = 1; i < M; ++i) cout << ", " << getvar(i,i+1);
		cout << " }" << endl;
	}
};

int main() {
	int N,M; cin >> N >> M;
	Lazy_Segment_Tree_Range_Sum_Query<int> Seg(M+2,0);
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
		for(int j = i; j <= M; j += i) ans[i] += Seg[j];
		
	}
	for(int i  = 1; i <= M; ++i) cout << ans[i] << endl;	
	return 0;
}
