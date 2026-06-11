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
	int n;
	cin >>n;
	VI a(n);
	rep(i, n) cin>>a[i];
	
	auto b =a; sort(all(b));
	bool ok =true;
	
	rep(i, n){
		if(i%2){
			if(i + n%2 != b[i]) ok=false;
		}else{
			if(i + (n%2==0) != b[i]) ok=false;
		}
	}
	
	if(!ok){puts("0"); return 0;}
	ll ans = 1;
	rep(i, n/2) ans = ans * 2LL %MD;
	cout << ans <<"\n";
	return 0;
}
