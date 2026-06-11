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
	
	ini(n);
	ini(n1);
	vi morty;
	FOR(i,0,n1){
		ini(x);
		morty.push_back(x);
	}
	if(n1 == 1){
		out(n-1);
		return 0;
	}
	while(n>0){
		sort(all(morty),greater<int>());
		//for(auto x:morty){cout<<x<<" ";}cout<<"\n";
		if(morty[1] == 0)if(morty[0]!=0){out(morty[0]-1);return 0;}
		morty[0]--;morty[1]--;
		n-=2;
	}
	out(0);















	return 0;
}