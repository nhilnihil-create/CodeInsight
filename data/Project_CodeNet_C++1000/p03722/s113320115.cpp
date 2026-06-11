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
	int n, m;
	cin >>n >>m;
	
	vector<vector<pii>> r(n);
	rep(i, m){
		int a, b, c; cin >>a >>b >>c;
		r[a-1].emplace_back(b-1, c);
	}
	const ll inf = 1LL<<60;

	auto bellman = [&](int s){
		vector<ll> ds(n, -inf);
		ds[s] =0;
		for(int i =0, nxt =1; i<n+3 && nxt>0 ; i++){
			nxt = 0;
			rep(j, n) for(auto z: r[j]){
				if(ds[j] != -inf && ds[z.first] < ds[j] + z.second){
					ds[z.first] = ds[j] + z.second;
					nxt = 1;
					if(i>n && z.first==n-1) {ds[s] = inf; return ds;}
				}
			}
			//if(i>n ) {ds[s] = inf; return ds;}
		}
		return ds;
	};
	auto ans = bellman(0);
	if(ans[0] ==inf) puts("inf");
	else cout << ans[n-1] <<"\n";
	return 0;
}
