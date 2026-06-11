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
	int n, k;
	cin >>n >>k;
	VI a(n);
	rep(i, n) cin >>a[i];
	a.push_back(k); n++;
	sort(all(a));
	
	auto f=[&](int m){
		if(a[m] >= k) return true;
		vector<int> dp(k+3, 0);
		dp[0] = 1;
		rep(i, n) if(i !=m){
			repr(j, k, 0) if(dp[j] >0){
				int nj = min(j+a[i], k);
				dp[nj] = 1;
				if(nj >= k-a[m] && nj < k) return true;
			}
		}
		return false;
	};
	
	int lf = -1, rg = n-1;
	while(rg - lf >1){
		int md = (rg + lf) >> 1;
		if( f(md) ) rg = md; else lf = md; 
	}

	cout << rg <<"\n";
	return 0;
}
