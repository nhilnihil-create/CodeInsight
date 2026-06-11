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

	vector<vector<ll>> mkcmb(const int MX){
		vector<vector<ll>> cmb(MX+2, vector<ll>(MX+2));
		rep(i,MX+1)  cmb[i][0] = 1;
		rep2(i,1,MX+1) rep2(j,1,i+1)
			cmb[i][j] = (cmb[i-1][j] + cmb[i-1][j-1]);
		return cmb;
	}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, a, b;
	cin >>n >>a >>b;
	VL v(n), sm(n+1);
	rep(i, n) cin >>v[i];
	sort(v.rbegin(), v.rend());
	rep(i, n) sm[i+1] = sm[i] + v[i];
	
	auto ncr = mkcmb(55);
	
	ll ans = 0;
	rep2(i, a, b+1){
		int cnt=0, ndc=0;
		if(v[i-1] < v[a-1]) break;
		if(sm[a]*i != sm[i]*a) break;
		rep(j, n) if(v[a-1]==v[j]){
			cnt++;
			if(j < i) ndc++;
		}
		//dbg(i,cnt, ndc);
		ans += ncr[cnt][ndc];
	}
	
	printf("%.14f\n%lld\n", (double)sm[a] /a,  ans);
	
	return 0;
}
