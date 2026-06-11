// by batr (TBhero.17)                      
// This will be Accepted!
// why am I so dumb ? :c
 
#include <bits/stdc++.h>
 
#define jyldam ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
#define pb push_back
#define mp make_pair
 
#define B begin()
#define E end()
#define sz size()
#define skip continue
#define all(x) (x).begin(), (x).end()
 
#define ai a[i]
#define F first
#define S second          
 
#define st(x) st+=x
#define pli pair<long long, int>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;     
 
const int N = 1e6 + 17, M = N * 4, D = 2e3 + 17, mod = 1e9 + 7;
const ll INF = 1e17 + 17;
 
int tt = 1;  
int n, x;
int a[D][D];
ll b[D][D];
ll ans;
 
void solve () {          
			cin >> n >> x;
			for (int i = 1; i <= n; i++) {
					cin >> a[i][0];
					ans += a[i][0];
			}		                 
			for (int k = 1; k < n; k++) {
					ll lol = k * 1ll * x;
					for (int i = 1; i <= n; i++) {
							int id = i;
							if (id > 1) {
								id--;
							}
							else {
								id = n;
							}
							a[i][k] = min(a[i][0], a[id][k-1]);
							lol += a[i][k];
					}
					ans = min(lol, ans);
			}
			cout << ans;
}
		
int main() {
		jyldam;   
                  
		while (tt--) {   
			solve();
		}
   	
		return 0;
}