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
	int h, w, n;
	cin >>h >>w >>n;
	VI a(n);
	rep(i, n) cin >>a[i];
	vector<VI> ba(h, VI(w));
	int cr = 0;
	rep(i, n){
		rep(j, a[i]){
			int y=cr/w, x = y%2?  w-1 -cr%w: cr%w;
			ba[y][x] = i+1;
			cr++;
		}
	}
	for(auto xl: ba){for(auto x :xl) cout<<x<<" "; cout<<"\n";}

	return 0;
}
