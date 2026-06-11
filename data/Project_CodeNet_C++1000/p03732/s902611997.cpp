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
	int n; ll mw;
	cin >>n >>mw;
	VL w(n), v(n);
	rep(i, n) cin >>w[i] >>v[i];
	ll khw = w[0], ans = 0;
	vector<VL> dp(n+2, VL(3*n+5));
	
	rep(i, n){
		repr(j, n, 0) repr(k, 3*n+1, 0) if(k==0 || dp[j][k]>0){
			if(khw*j + k + w[i] <= mw){
				dp[j+1][k+w[i]-khw] = max(dp[j+1][k+w[i]-khw] , dp[j][k] + v[i]);
				ans = max(ans, dp[j+1][k+w[i]-khw]);
			}
		}
	}
	cout << ans <<"\n";
	return 0;
}
