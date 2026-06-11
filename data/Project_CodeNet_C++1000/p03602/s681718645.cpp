#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

ll MOD = (ll) 10939;
const ll MAXN = (ll) 3e2 + 10;
const ll INF = (ll) 1e17;
const ll LOG = 20;

ll dis[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> dis[i][j];
	ll mn, ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			mn = INF;
			for(int k = 1; k <= n; k++){
				if(k == i || k == j) continue;
				mn = min(mn, dis[i][k] + dis[k][j]);
			}
			if(dis[i][j] > mn) return cout << -1, 0;
			if(dis[i][j] < mn) ans += dis[i][j];
		}
	}
	cout << ans;
	return 0;
}
