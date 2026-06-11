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
	ll n;
	cin >>n;
	VI a(n);
	rep(i, n) cin >>a[i];
	
	VI sk(100010), tk(4);
	rep(i, n) sk[a[i]]++;
	rep(i, 100001){
		if(sk[i]>2 ) sk[i] = sk[i]%2? 1: 2;
		tk[sk[i]]++;
	}
	cout << tk[1] + tk[2] - (tk[2]%2) <<"\n";
	return 0;
}
