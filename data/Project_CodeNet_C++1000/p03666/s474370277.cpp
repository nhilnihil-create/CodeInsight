#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <utility>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <stdio.h>
#include <deque>

using namespace std;

#define REP(i,n,m) for( long long int i = (n); i < (m); i++ )
#define REV(v) for (auto itr = v.rbegin(); itr != v.rend(); itr++)
#define ll long long
#define ALL(a) (a).begin(), (a).end()
#define SORT(v) sort( ALL(v) );
#define LAST(v) v[v.size()-1]
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define pi pair<int, int>
#define MP make_pair
#define PB push_back
#define IIN(a) int a; cin >> a;
#define LIN(a) ll a; cin >> a;
#define SIN(a) string a; cin >> a;
#define VL(v,n) vector<ll> v(n);
#define Read_VL(v,n) vector<ll> v(n);REP(i,0,n)cin>>v[i];
#define sumV(v,n) Vl(acm,n) REP(i,0,n) acm[i] = v[i] + ( i == 0 ? 0 : acm[i - 1]);
#define EPS (1e-10)
#define INF 1000000000000LL

void YN(bool b){cout<<(b?"YES":"NO")<<"\n";}
void Yn(bool b){cout<<(b?"Yes":"No")<<"\n";}
void yn(bool b){cout<<(b?"yes":"no")<<"\n";}

template<class S>S max(vector<S>&a){return *max_element(all(a));}
template<class S>S min(vector<S>&a){return *min_element(all(a));}

template<class T>void puta(T&&t){cout<<t<<"\n";}
template<class H,class...T>void puta(H&&h,T&&...t){cout<<h<<' ';puta(t...);}


template<class T=ll>struct Graph{
	int n;
	vector<vector<tuple<ll,T>>>edge;
	Graph(int N=1):n(N){edge.resize(n);}
	void add(ll f,ll t,T c,bool d=false){
		edge[f].emplace_back(t,c);
		if(!d)edge[t].emplace_back(f,c);
	}
	void view(){
		REP(i,0,n)for(auto&e:edge[i])
			puta(i,"=>",get<0>(e),", cost :",get<1>(e));
	}
};


int MOD=1000000007;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
//I ASCII code: '0' = 48; 'A' = 65; 'a' = 97

ll StoLL( string s )
{
	ll num=0;
  REP( i, 0, s.size() ){
    num = num*10 + ( s[i]^48 );
  }
  return num;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LIN(n)
    LIN(a)
    LIN(b)
    LIN(c)
    LIN(d)
    bool cond = false;

    REP( i, 0, n ){
      ll l = c * i - d * ( n - i - 1 ), r = d * i - c * ( n - i - 1 );
      if( l <= b - a && b - a <= r ){
        cond = true;
      }
    }

    YN( cond ) ;
    return 0;
}
