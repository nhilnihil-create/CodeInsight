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
	int n, q, k;
	string s1, s2;
	cin >>n >>s1 >>s2;
	ll ans = 1;
	rep(i, n){
		if(s1[i] == s2[i]){
			if(i==0) ans = 3;
			else if(s1[i-1] != s2[i-1]) ans *=1;
			else ans *=2;
		}else{
			if(i==0) ans = 6;
			else if(s1[i-1] != s2[i-1])ans *=3;
			else ans *=2;
			i++;
		}
		ans %=MD;
	}
	cout << ans <<"\n";
	return 0;
}
