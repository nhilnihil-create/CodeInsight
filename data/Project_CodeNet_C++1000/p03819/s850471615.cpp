#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
constexpr double EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max()/2;
constexpr int MOD = 1e9+7;

template <typename T>
class fenwick_tree {
	const int n;
	vector<T> data;
public:
	fenwick_tree(int n_) : n(n_), data(n) {}
	T find(int p) const {
		T res = 0;
		while (p >= 0) {
			res += data[p];
			p = (p & (p + 1)) - 1;
		}
		return res;
	}
	void add(int p, T val) {
		while (p < n) {
			data[p] += val;
			p |= p + 1;
		}
	}
};

// [l, r)
template <typename T>
class range_add_range_sum {
	const int n;
	fenwick_tree<T> bit0, bit1;
public:
	range_add_range_sum(int n_) : n(n_), bit0(n), bit1(n) {}
	T find(int p) const {
		return bit1.find(p) * (p + 1) + bit0.find(p);
	}
	T find(int l, int r) const {
		return find(r - 1) - find(l - 1);
	}
	void add(int l, int r, T val) {
		bit0.add(l, -val * l);
		bit1.add(l, val);
		bit0.add(r, val * r);
		bit1.add(r, -val);
	}
};

range_add_range_sum<int> ft(111111);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;cin>>n>>m;
    vector<vector<P>> v(m+1);
    for(int i=0;i<n;i++){
        int l,r;cin>>l>>r;
        v[r-l+1].push_back(P(l,r));
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
       int res=n-cnt;
       for(int j=i;j<=m;j+=i){
           res += ft.find(j,j+1);
       }
       cout<<res<<endl;
       for(int j=0;j<(int)v[i].size();j++){
           int l=v[i][j].first,r=v[i][j].second;
           ft.add(l,r+1,1);
       }
       cnt += v[i].size();
    }
}
