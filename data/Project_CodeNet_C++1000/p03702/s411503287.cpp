#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repA(i, a, n) for(int i = a; i <= (n); ++i)
#define repD(i, a, n) for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a) memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 19;
int n,a,b; 
vi h;

bool chk(ll t){
	ll cnt = 0;
	rep(i,n){
		if((h[i]+b-1)/b > t){
		   cnt += (h[i]-t*b + a - b - 1)/(a-b);
		}
	}
	return cnt <= t;
}	

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> n >> a >> b;
	h.resize(n);
	rep(i,n) cin >> h[i];
	sort(all(h));
	reverse(all(h));
	ll lo = 0, hi = LLONG_MAX/100, mid = (lo+hi)/2;	
	while(hi-lo>1){
		if(chk(mid)){
			hi = mid;
		}else{
			lo = mid;
		}
		mid = (hi+lo)/2;
	}
	cout << hi << endl;
	return 0;
}

