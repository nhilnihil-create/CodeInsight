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
	int n, a;
	cin >>n >>a;
	VI p(n);
	rep(i, n) cin >>p[i];
	int sm = accumulate(all(p), 0);
	
	vector<VL> dp(n+2, VL(sm +10));
	dp[0][0] =1;
	rep(i, n) repr(j, n, 0) rep(k, sm) if(dp[j][k]>0){
		if(k + p[i] <= sm){
			dp[j+1][k+p[i]] += dp[j][k];
		}
	}
	
	ll ans =0;
	rep2(i, 1, n+1) if(i*a <= sm){
		ans += dp[i][i*a];
	}
	cout << ans <<"\n";
	return 0;
}
