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
	int n;
	cin >>n;
	VI a(3*n);
	rep(i, 3*n) cin >>a[i];
	
	priority_queue<ll, vector<ll>, greater<ll> > pl;
	priority_queue<ll> pr;
	
	ll sml=0, smr=0;
	VL lf(3*n), rg(3*n);
	rep(i, 3*n){
		sml += a[i];
		pl.push(a[i]);
		if(sz(pl) >n){ sml -=pl.top(); pl.pop();}
		lf[i] = sml;
	}
	repr(i, 3*n-1, 0){
		smr += a[i];
		pr.push(a[i]);
		if(sz(pr) >n){ smr -=pr.top(); pr.pop();}
		rg[i] = smr;
	}

	ll ans = -1LL<<60;
	rep2(i, n-1, 2*n) ans = max(ans, lf[i] - rg[i+1]);
	cout << ans <<"\n";
	return 0;
}
