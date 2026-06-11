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
	int h, w;
	cin >>h >>w;
	if(h%3==0 || w%3==0){puts("0"); return 0;}
	
	auto cker=[](ll hh, ll ww) ->ll{
		

		ll ans = hh%3? ww : 0;
		
		rep2(i, 1, hh){
			ll a = i *ww;
			
			ll wb = ww /2;
			ll b = (hh-i)*wb;
			ll c = (hh-i)*(ww-wb);
			if(a<=0 || b<=0 || c<=0) continue;
			ll cnd = max({a,b,c}) - min({a,b,c});
			ans = min(ans, cnd);
		}
		return ans;
	};
	
	cout << min(cker(h,w),  cker(w,h)) <<"\n";
	return 0;
}
