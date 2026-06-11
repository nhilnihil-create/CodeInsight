#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
#include "set"
#include "stack"
#include "tuple"

#define rep(n) for (int i = 0; i < n; ++i)
#define REP(n,i) for (int i = 0; i < n; ++i)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define mkt make_tuple
#define P pair<ll, ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;

int n,m,q,a,b,v,d,c;
vector<int>V[100000];
iP g[100000][11];

int main() {
	cin>>n>>m;
	rep(n){
		REP(11,j)
			g[i][j]=mkp(-1,0);
		V[i].push_back(i);
	}
	rep(m){
		cin>>a>>b;
		V[a-1].push_back(b-1);
		V[b-1].push_back(a-1);
	}
	cin>>q;
	rep(q){
		cin>>v>>d>>c;
		g[v-1][d]=mkp(i,c);
	}
	for(int i=9;i!=-1;--i){
		REP(n,j){
			REP(V[j].size(),k){
				if(g[V[j][k]][i].first<g[j][i+1].first)
					g[V[j][k]][i]=g[j][i+1];
			}
		}
	}
	rep(n)
		cout<<g[i][0].second<<endl;
	return 0;
}
