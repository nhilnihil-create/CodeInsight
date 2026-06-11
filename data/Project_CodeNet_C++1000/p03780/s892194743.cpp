#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; }  template <typename T,typename ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T> void amin(T& a,T b){ a=min(a,b);}

array<bool, 5050> dp;

bool ck(int s, int k, const VI& v){
	int n=sz(v);
	if(v[s] >=k) return true;
	dp.fill(false); dp[0]=true;
	rep(j, n) if(s!=j ) {
		repr(u, k, 0) if(dp[u] && u+v[j] <=k){
			dp[u+v[j]] = true;
			if(u+v[j]>=k-v[s] && u+v[j]<k){
				//dbg(s,dp[s],"true");
				return true;
			}
		}
	}
	return false;
}




int main(){
	//cin.tie(0); ios_base::sync_with_stdio(false);
	int n,k;
	cin >>n >>k;
	VI a(n);
	for(auto& z: a) cin >>z;
	a.push_back(k); n++;
	sort(all(a));

	//int ans =0;
	//for(auto x :a) cerr<<x<<" "; puts("");
	//rep(i, sz(a)){
	//	if(!ck(i, k, a)) ans++;;
	//}
	//dbg(ans);
	int lo=0-1, hi=n-1;
	while(hi - lo >1){
		int md = (hi + lo) >> 1;
		if( ck(md, k, a) ) hi = md; else lo = md; 
	}
	cout << hi <<"\n";
	return 0;
}