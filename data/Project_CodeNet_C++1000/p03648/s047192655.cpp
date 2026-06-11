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

/*
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
void dfs(int x,int y){
		if(x == n+1){
			int tmp = 0;
			FOR(i,0,k){
				if(tmp1[mortyy[i]]-tmp1[morty[i]] == mortyyy[i])tmp+=mortyyyy[i];
			}
			rick = max(rick,tmp);
			return ;
		}
		int i;
		for(i = y;i<=n1;i++){
			tmp1[x] = i;
			dfs(x+1,i);
		}
	}
*/


//3111111111111111111111111111111




	void solve(){
		
		ini(k);
		vi morty(50);
		FOR(i,0,50)morty[i] = 49+k/50;
		k%=50;
		while(k--){
			morty[k]+=51;
			FOR(i,0,50)morty[i]-=1;
		}
		out(50);
		FOR(i,0,50){
			cout<<morty[i]<<" ";
		}
		out();



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