#include <bits/stdc++.h>
using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long 
const long long inf=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long, long > > vpll;
typedef vector<pair<int, int > > vpii;
#define FORR(x,arr) for(auto& x:arr)
#define ZERO(a) memset(a,0,sizeof(a))





//3111111111111111111111111111111

	void solve(){



		ini(n);
		ini(k);
		vi morty(n);
		FOR(i,0,n)in(morty[i]);
		int tmp = inf;
		FOR(i,0,1<<n){
			int tmp1 = 0;
			FOR(i1,0,21){
				if(1<<i1 & i)tmp1++;
			}
			if(tmp1 != k)continue;
			int tmpp = 0;
			int tmp_ = 0;
			tmp1 = 0;
			FOR(i1,0,n){
				if(1<<i1 & i){
					tmpp = max(tmp_+1,morty[i1]);
					tmp1+=tmpp-morty[i1];
					tmp_ = tmpp;
					//out(i1,i,tmpp,tmp1,tmp_);
				}
				else{
					tmp_ = max(tmp_,morty[i1]);
				}
			}
			//out(tmp1,31);
			tmp = min(tmp,tmp1);
		}
		out(tmp);			







	}	























int32_t main() {
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall 
	oneforall

	solve();
	


	return 0;
}
