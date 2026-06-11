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
	vi morty(n);
	FOR(i,0,n){
		in(morty[i]);
	}
	vi rick(n);
	vi rick1(n);
	FOR(i,0,n){
		rick[morty[i]-1] = 30000*(morty[i]);
		rick1[morty[i]-1] = 30000*(n-morty[i])+i+1;
	}
	FOR(i,0,n){
		cout<<rick[i]<<" ";
	}
	out();
	FOR(i,0,n){
		cout<<rick1[i]<<" ";
	}














	return 0;
}
