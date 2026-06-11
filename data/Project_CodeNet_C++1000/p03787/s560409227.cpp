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

ll k,s,t,n;

class UnionFind {
private:
    int sz;
    vector<int> par, nrank;
public:
    UnionFind(){}
    UnionFind(int node_size) : sz(node_size), par(sz), nrank(sz, 0){
        iota(par.begin(), par.end(), 0);
    }
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x,int y){
        x = find(x), y = find(y);
        if(x == y) return;
    	if(nrank[x] < nrank[y]) swap(x,y);
        par[y] = x;
        if(nrank[x] == nrank[y]) nrank[x]++;
    }
    bool same(int x,int y){
        return find(x) == find(y);
    }
};

vector<vector<int> > g;
bool flag[100001];
bool black[100001];
int dfs(int id,bool b){
	black[id] = b;
	flag[id] = 1;
	int p = 0;
	for(auto x:g[id]){
		if(flag[x]){
			if(black[x]==black[id])p = 1;
		}else{
			p = max(p,dfs(x,!b));
		}
	}
	return p;
}
int main(){
	int m;
	cin >> n >> m;
	g.resize(n);
	rep(i,m){
		int a,b;
		cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	rep(i,n){
		if(g[i].size()==0){
			t++;
		}else if(!flag[i]){
			int x = dfs(i,0);
			if(x==0){
				k++;
			}else{
				s++;
			}
		}
	}
	//cerr << k << " " << s << " " << t << endl;
	cout << 2*k*k+2*k*s+s*s+2*t*(n-t)+t*t << endl;
	return 0;
}