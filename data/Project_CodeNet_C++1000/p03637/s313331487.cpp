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
	rep(i, n) cin >>a[i];
	VI sk(3);
	for(auto x:a){
		if(x %4 ==0) sk[0]++;
		else if(x %2 ==0) sk[1]++;
		else sk[2]++;
	}
	//for(auto x :sk) cerr<<x<<" "; dbg("");
	bool ok=false;
	if(sk[0] +1 >= sk[2] + (sk[1] >0) ) ok=true;
	
	puts(ok? "Yes": "No");
	return 0;
}
