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
		vi morty(n+1);
		vi pos(n+1);
		int rick = 0;
		FOR(i,1,n+1){
			in(morty[i]);
			pos[morty[i]] = i;
		}
		set<int>set1;
		set1.insert(0);
		set1.insert(n+1);
		FOR(i,1,n+1){
			auto pos1 = set1.upper_bound(pos[i]);
			int rr = *pos1;
			pos1--;
			int ll = *pos1;
			rick+= (1ll*i)*(rr-pos[i])*(pos[i]-ll);
			set1.insert(pos[i]);
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
