#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n;
	cin >> n;
	++n;
	vi s;
	int i = 63 - __builtin_clzll(n);
	rep(j,1,i+1) s.insert(s.begin(),j);
	rep(j,1,i+1) s.insert(s.begin(),j);
	n -= 1LL<<i;
	++i;
	while(n){
		int j = 63 - __builtin_clzll(n);
		s.insert(s.end()-j, i++);
		s.insert(s.begin(), i-1);
		n -= 1LL<<j;
	}
	cout << sz(s) << endl;
	trav(x, s) cout << x << ' ';
}