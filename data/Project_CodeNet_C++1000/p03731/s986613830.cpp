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
	int n; ll t;
	cin >>n >>t;
	VL p(n);
	rep(i, n) cin >>p[i];
	ll ans = 0, bgn = 0;
	rep2(i, 1, n){
		if(p[i] - p[i-1] >= t){
			ans += t;
		}else{
			ans += p[i] - bgn;
		}
		bgn = p[i];
	}
	
	cout << ans + t <<"\n";

	return 0;
}
