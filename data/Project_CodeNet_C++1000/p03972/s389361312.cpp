#include <bits/stdc++.h>
#include <boost/functional/hash.hpp>

#define debug 0
#define esc(ret) cout << (ret) << endl,quick_exit(0)
#define fcout(d) cout << fixed << setprecision(d)
#define repU(i,s,t) for(int i = (int)(s); i <= (int)(t); ++i)
#define repD(i,s,t) for(int i = (int)(s); i >= (int)(t); --i)
#define rep(i,n) repU(i,0,(n) - 1)
#define rep1(i,n) repU(i,1,(n))
#define all(v) begin(v),end(v)
#define vct vector
#define prique priority_queue
#define l_bnd lower_bound
#define u_bnd upper_bound
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define ins insert
#define emp emplace
#define era erase
#define fir first
#define sec second
#define odd(x) (x & 1)
#define even(x) (!odd(x))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef pair<db,int> pdi;
typedef tuple<int,int,int> tiii;

const int dir[][2] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const int mod = 1e9 + 7;
const int inf32 = (1 << 30) - 1;
const ll inf64 = (1LL << 62) - 1;

template <class T, class U> T qceil(T x, U y) { return x > 0 ? (x - 1) / y + 1 : x / y; }
template <class T, class U> bool parity(T x, U y) { return odd(x) ^ even(y); }
template <class T, class U> bool chmax(T &m, U x) { if(m < x) { m = x; return 1; } return 0; }
template <class T, class U> bool chmin(T &m, U x) { if(m > x) { m = x; return 1; } return 0; }
template <class T> bool cmprs(T &v) {
    T tmp = v;
    sort(all(tmp));
    tmp.erase(unique(all(tmp)),end(tmp));
    for(auto it = begin(v); it != end(v); ++it) *it = l_bnd(all(tmp),*it) - begin(tmp) + 1;
    return v.size() > tmp.size();
}

template <class Abel> struct BItree {
	int range,modulo;
	vector<Abel> data_;

	BItree(int size_, Abel val = 0, int m = mod) {
		range = size_ + 1,modulo = m;
		init(range,val);
	}

	void init(int n, int val) {
		data_.assign(n,val);
	}

	Abel sum(int r) {
		Abel s = 0;
		for(; 0 < r; r -= r & -r) {
			s = (s + data_[r]) % modulo;
		}
		return s;
	}

	Abel sum(int l, int r) { return (sum(r) - sum(l - 1)) % modulo; }

	void add(int idx, Abel diff) {
		for(; idx < range; idx += idx & -idx) {
			data_[idx] = (data_[idx] + diff) % modulo;
		}
	}

	void update(int idx, Abel val) {
		int prev = sum(idx, idx);
		add(idx, val - prev);
	}

	int lower_bound(Abel obj) {
		int lower = 0;
		int upper = range;
		while (upper - lower > 1) {
			int mid = (lower + upper) / 2;
			if(sum(mid) < obj) lower = mid;
			else upper = mid;
		}
		return upper;
	}

	int upper_bound(Abel obj) {
		int lower = 0;
		int upper = range;
		while (upper - lower > 1) {
			int mid = (lower + upper) / 2;
			if(sum(mid) > obj) upper = mid;
			else lower = mid;
		}
		return upper;
	}
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll W,H;cin>>W>>H;
    ll w=W+1,h=H+1;
    vct<pii> cost(W+H);
    rep(i,W) cin>>cost[i].fir,cost[i].sec=0;
    rep(i,H) cin>>cost[i+W].fir,cost[i+W].sec=1;
    ll rem=W*H+W+H,ans=0;
    sort(all(cost));
    for(int i=0;i<W+H&&rem>0;i++){
        int c=cost[i].fir;
        int t=cost[i].sec;
        if(t){
            rem-=w;
            ans+=w*c;
            h-=1;
        }else{
            rem-=h;
            ans+=h*c;
            w-=1;
        }
    }
    cout<<ans<<endl;
}
