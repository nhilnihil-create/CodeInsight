#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;

int main(){
	int n,m,q;
	cin>>n>>m;
	vector<int> a(m),b(m),mx(n+1,-1),ans(n+1,0);
	vector<vector<int>> g=vector<vector<int>>(n+2,vector<int>());
	FOR(i,0,m){
		cin>>a[i]>>b[i];
		g[a[i]].PB(b[i]);
		g[b[i]].PB(a[i]);
	}
	cin>>q;
	vector<int> v(q),d(q),c(q);
	FOR(i,0,q)cin>>v[i]>>d[i]>>c[i];

	FORD(i,q,0){
		queue<pair<pair<int,int>,int>> q;
		q.push(MP(MP(v[i],d[i]),c[i]));
		while(q.size()){
			pair<pair<int,int>,int> tpl=q.front();
			q.pop();
			int vv=tpl.ST.ST,dd=tpl.ST.ND,cc=tpl.ND;
			if(mx[vv]>=dd)continue;
			mx[vv]=dd;
			if(ans[vv]==0)ans[vv]=cc;
			int l=g[vv].size();
			FOR(j,0,l){
				if(mx[g[vv][j]]<dd-1){
					q.push(MP(MP(g[vv][j],dd-1),cc));
				}
			}
		}
	}
	FORQ(i,1,n){
		cout<<ans[i]<<endl;
	}
    return 0;
}
