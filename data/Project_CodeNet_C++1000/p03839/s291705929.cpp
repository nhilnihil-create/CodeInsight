#include <bits/stdc++.h>
using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long 
const long long INF=1e18;
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
		ini(n1);
		int pre[n+1];
		int tmppre[n+1];
		ZERO(pre);
		ZERO(tmppre);
		FOR(i,0,n){
			ini(x);
			pre[i+1] = pre[i]+x;
			tmppre[i+1] = tmppre[i]+max(0LL,x);
		}
		int rick = 0;
		FOR(i,0,n-n1+1){
			int LL = tmppre[i];
			int mid = max(0LL,pre[i+n1]-pre[i]);
			int RR = tmppre[n]-tmppre[i+n1];
			rick = max(rick,LL+mid+RR);
		}
		out(rick);















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
