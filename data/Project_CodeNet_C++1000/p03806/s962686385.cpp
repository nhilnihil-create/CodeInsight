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
template <class T, class T2> void amin(T& a,T2 b){ if(a > b) a = b;}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, ma, mb;
	cin >>n >>ma >>mb;
	VI a(n), b(n), c(n);
	rep(i, n) cin >>a[i] >>b[i] >>c[i];
	
	const int jmx = n*11;
	vector<VL> dp(jmx+11, VL(jmx+11, MD));
	dp[0][0] = 0;
	rep(i, n){
		repr(j, jmx, 0) repr(k, jmx, 0) if(dp[j][k] < MD){
			amin(dp[j+a[i]][k+b[i]] , dp[j][k] + c[i]);
		}
	}

	ll ans = MD;
	rep2(j, 1, jmx){
		if( j*mb % ma) continue;
		ll tk = (ll)j * mb / ma;
		if( tk > jmx) continue;
		if(dp[j][tk] < MD) ans = min(ans, dp[j][tk]);
	}
	cout << (ans !=MD? ans: -1) <<"\n";
	return 0;
}
