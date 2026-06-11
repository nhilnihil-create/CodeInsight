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
	int n, m;
	cin >>n >>m;
	vector<VI> r(n, VI(n, MD));
	rep(i, n) r[i][i] =0;
	rep(i, m){
		int a, b, c;
		cin >>a >>b >>c;
		r[a-1][b-1] = r[b-1][a-1] = c;
	}
	auto org = r;
	rep(k,n) rep(i,n) rep(j,n) r[i][j] =min(r[i][j], r[i][k] + r[k][j]);
	
	ll ans =0;
	rep(i, n) rep2(j, i+1, n) if(org[i][j] < MD && org[i][j] > r[i][j]) ans++;
	cout << ans <<"\n";
	return 0;
}
