#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<functional>
#include<queue>
#include <iomanip>
#include<map>
#include<limits>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<utility>
#include<complex>
#include<cstdlib>
#include<set>
#include<cctype>

#define DBG cerr << '!' << endl;
#define REP(i,n) for(int (i) = (0);(i) < (n);++i)
#define rep(i,s,g) for(int (i) = (s);(i) < (g);++i)
#define rrep(i,s,g) for(int (i) = (s);i >= (g);--(i))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int i = 0;i < (n);i++)cerr << v[i] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef vector<int> iv;
typedef vector<iv> iiv;
typedef vector<string> sv;

#define MAX_N 200010
struct UF
{
	vector<int> par; // 親
	// 初期化
	UF(int n):par(n) {
		for(int i = 0; i < MAX_N; i++){
			par[i] = i;
		}
	}
	// 木の根を求める
	int find(int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}
	// xとyの属する集合を併合
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		// 木の高さが高い方を代表ノードにする
		par[x] = y;
	}
	// xとyが同じ集合ならtrue
	bool same(int x, int y) { return find(x) == find(y); }
};

map<pair<int,int>,int> mp;

int main()
{
	UF D(200010);
	UF T(200010);
	
	int n,k,l;cin >> n >> k >> l;
	
	REP(i,k)
	{
		int p,q;cin>> p>>q;
		D.unite(p-1,q-1);
	}
	REP(i,l)
	{
		int r,s;cin>>r>>s;
		T.unite(r-1,s-1);
	}
	
	REP(i,n)
	{
		int a = D.find(i);int b = T.find(i);
		if(mp.find(MP(a,b)) == mp.end())mp[MP(a,b)] = 1;
		else mp[MP(a,b)]++;
	}
	
	REP(i,n-1)
	{
		cout << mp[MP(D.find(i),T.find(i))] << ' ';
	}
	cout << mp[MP(D.find(n-1),T.find(n-1))] << endl;
	
	return 0;
}