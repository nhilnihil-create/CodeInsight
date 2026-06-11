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
	string s;
	cin >>s;
	int gct =0, pct =0;
	int ans =0;
	for(auto ch: s){
		if(pct < gct){
			pct++;
			ans += ch == 'g';
		}else{
			gct++;
			ans -= ch == 'p';
		}
	}
	
	cout << ans <<"\n";
	return 0;
}
