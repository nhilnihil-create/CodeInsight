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

bool isprime(int x){
	for(int i = 2;i*i<=x;i++){
		if(x%i == 0)return false;
	}
	return x!=1;
}
int gcd(int a, int b) 
{ 
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    if (a == b) 
        return a; 
   
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 


//3111111111111111111111111111111






	void solve(){

		ini(n);
		vi morty;
		vi mortysort;
		FOR(i,0,n){
			ini(x);
			morty.push_back(x);
			mortysort.push_back(x);
		}
		sort(all(mortysort));
		int tmp  = 0;
		FOR(i,0,n){
			int x1 = lower_bound(all(mortysort),morty[i])-mortysort.begin();
			if((x1+i)%2)tmp++;
		}
		out(tmp/2);



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