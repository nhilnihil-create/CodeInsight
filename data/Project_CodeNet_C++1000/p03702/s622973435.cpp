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


	vi morty(310000);
	int n;
	int x;
	int x1;
	bool ok(int explosions){
		int tmp = 0;
		FOR(i,0,n){
			if(morty[i]-x1*explosions<=0)continue;
			tmp+=((morty[i]-x1*explosions)+(x-x1)-1)/(x-x1);
		}
		//out(explosions,tmp);
		if(tmp<=explosions)return 1;
		else return 0;
	}

	void solve(){

		in(n);
		in(x);
		in(x1);
		FOR(i,0,n)in(morty[i]);
		int ll = 1;
		int rr = 1e9;
		while(ll+1<rr){
			int mid  = (ll+rr)/2;
			if(ok(mid))rr = mid;
			else ll = mid;
		}
		if(ok(ll))out(ll);
		else out(rr);








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
