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

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	string a; cin >> a;
	set <char> se;
	int n = sz(a);
	vi sep; sep.pb(n);
	repD(i,n-1,0){
		se.insert(a[i]);
		if(sz(se) == 26){
			sep.pb(i);
			se.clear();
		}
	}
	sort(all(sep));
	string ans = "";
	rep(i,26){
		if(se.find('a' + i) == se.end()){
			ans += char('a'+ i);
			break;
		}
	}
	se.clear();
	int m = sz(sep);
	int ind = 0;
	rep(i,n) if(a[i] == ans[0]){ ind = i; break; }
	repA(i,1,m-1){
		ind++;
		for(int j = ind; j < sep[i]; j++){
			se.insert(a[j]);
		}
		rep(j,26){
			if(se.find('a' + j) == se.end()){
				ans += char('a'+ j);
				break;
			}
		}
		se.clear();
		if(i != m-1) for(; a[ind] != ans[i]; ind++);
	}
	cout << ans << endl;
	return 0;
}

