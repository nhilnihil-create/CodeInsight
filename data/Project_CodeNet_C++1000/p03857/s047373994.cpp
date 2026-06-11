#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const double EPS = 1e-10;
const ll INF = 100000000;
const ll MOD = 1000000007;

const int MAX_N = 200000;

struct UF{
	int par[MAX_N];
	int rank[MAX_N];
	int si[MAX_N];

	void init(int n){
		rep(i,n){
			par[i] = i;
			rank[i] = 0;
			si[i] = 1;
		}
	}

	int find(int x){
		if(par[x] == x) return x;
		else return par[x] = find(par[x]);
	}

	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		
		if(rank[x] < rank[y]){
			par[x] = y;
			si[y] += si[x];
		} else{
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
			si[x] += si[y];
		}
	}

	bool same(int x, int y){
		return find(x) == find(y);
	}
} uf[2];

int n, k, l;
map<P,int> ma;

int main(){
    cin >> n >> k >> l;
    rep(i,2) uf[i].init(n);
    rep(i,k) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        uf[0].unite(p,q);
    }
    rep(i,l) {
        int r, s;
        cin >> r >> s;
        r--; s--;
        uf[1].unite(r,s);
    }
    rep(i,n) {
        P x = P(uf[0].find(i), uf[1].find(i));
        ma[x]++;
    }
    rep(i,n) {
        P x = P(uf[0].find(i), uf[1].find(i));
        cout << ma[x];
        if (i != n-1) cout << " ";
        else cout << endl;
    }
}






























