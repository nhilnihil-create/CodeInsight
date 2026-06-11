#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T> class segtree {
private:
    int n,sz,h;
    vector<T> node, lazy;
    void eval(int k) {
        if(lazy[k]){
            node[k] += lazy[k];
            if(k < n) {
                lazy[k*2] += lazy[k] / 2, lazy[k*2+1] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

public:
    segtree(vector<T>& v) : sz((int)v.size()), h(0) {
        n = 1;
        while(n < sz) n *= 2, h++;
        node.resize(2*n, 0), lazy.resize(2*n, 0);
        for(int i = 0; i < sz; i++) node[i+n] = v[i];
        for(int i = n-1; i >= 1; i--) node[i] = node[2*i] + node[2*i+1];
    }
    void range(int a, int b, T x) {
        a += n, b += n - 1;
        for(int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
        int ta = a, tb = b++, length = 1;
        while(a < b){
            if(a & 1) lazy[a++] += length * x;
            if(b & 1) lazy[--b] += length * x;
            a >>= 1, b >>= 1, length <<= 1;
        }
        while(ta >>= 1, tb >>= 1, ta){
            if(!lazy[ta]){
                eval(2*ta), eval(2*ta+1), node[ta] = node[2*ta] + node[2*ta+1];
            }
            if(!lazy[tb]){
                eval(2*tb), eval(2*tb+1), node[tb] = node[2*tb] + node[2*tb+1];
            }
        }
    }
    T query(int a, int b) {
        a += n, b += n - 1;
        for(int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
        b++;
        T res1 = 0, res2 = 0;
        while(a < b) {
            if(a & 1) eval(a), res1 += node[a++];
            if(b & 1) eval(--b), res2 += node[b];
            a >>= 1, b >>= 1;
        }
        return res1 + res2;
    }
    void print(){for(int i = 0; i < sz; i++) cout<<query(i,i+1)<< " ";cout<<endl;}
};

int main(){
	int n,m;
	cin >> n >> m;
	vector< vector<pair<int,int> > >  v(m+1);
	rep(i,n){
		int a,b;
		cin >> a >> b;
		v[b-a].push_back(MP(a,b));
	}
	vector<int> r(m+1);
	segtree<int> sg(r);
	rep(d,m){
		if(d!=0){
			for(auto &x:v[d-1]){
				sg.range(x.first,x.second+1,1);
			}
			n-=v[d-1].size();
		}
		int sm = 0;
		int id = 0;
		while(id<=m){
			sm += sg.query(id,id+1);
			id += d+1;
		}
		cout << n+sm << endl;
	}
	return 0;
}