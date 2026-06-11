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
	int n; ll a, b;
	cin >>n >>a >>b;
	
	VL x(n);
	rep(i, n) cin >>x[i];
	
	VL df(n-1) ,sm(n);
	rep(i, n-1) df[i] = (x[i+1]-x[i]) * a;
	sort(all(df));
	rep(i, n-1) sm[i+1] = sm[i] + df[i];
	for(auto x :sm) cerr<<x<<" "; dbg("");
	auto cal=[&](ll m){
		rep(i, n){
			if(sm[n -1 - i] + i*b <= m) return true;
		}
		return false;
	};
	
	ll lf = 0, rg=1LL<<60;
	while(rg - lf >1){
		ll md = (rg + lf) >> 1;
		if( cal(md) ) rg = md; else lf = md; 
	}

	//dbg(lf, rg);
	cout << rg <<"\n";
	return 0;
}
