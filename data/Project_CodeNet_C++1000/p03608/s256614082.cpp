#include <bits/stdc++.h>


#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int MD = (int)1e9 + 7; typedef vector<ll> VL;
void dbg(){ cerr << "\n"; }  template <class T, class ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, m, rs;
	cin >>n >>m >>rs;
	VI r(rs);
	rep(i, rs){ cin >>r[i]; r[i]--;}
	vector<VI> g(n, VI(n, MD));
	rep(i, n) g[i][i] = 0;
	rep(i, m){
		int a, b, c;
		cin >>a >>b >>c;
		g[a-1][b-1] = g[b-1][a-1] = c;
	}
	
	rep(k,n) rep(i,n) rep(j,n) g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
	ll ans = 1LL<<50;
	sort(all(r));
	do {
		ll sm = 0;
		rep(i,rs-1) sm += g[r[i]][r[i+1]];
		ans = min(ans, sm);
	} while ( next_permutation(all(r)) );
	cout << ans <<"\n";
	
	
	return 0;
}
