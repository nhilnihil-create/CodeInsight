#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const int MOD = 1000000007;
const int LOG = 20;
const int INF = 1000000010;
const int delta = 11353;

int n, a[N];
vector<pii> P, M;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	//if (n == 1) return cout << (n % 2 == 1?"Second":"First"), 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == 1) return cout << (a[1] % 2 == 1?"Second":"First"), 0;
	sort(a + 1, a + n + 1);
	//int mx = 0, mx2 = 0;
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		P.pb({i, a[i]});
	}
	sort(all(P));
	int mx = 0;
	reverse(all(P));
	for (auto u:P){
		if (u.S <= mx) continue;
		mx = u.S;
		if (u.F == u.S) return cout << "Second", 0;
		M.pb({u.F, u.S});
	}
	//iassert(0);
	sort(all(M));
	for (int i = 1; i < M.size(); i++){
		if (M[i - 1].F < M[i - 1].S && M[i].F > M[i].S){
			int X = M[i - 1].F, Y = M[i].S;
			if (X == Y){
				if (((M[i - 1].S - Y) % 2 == 1) || ((M[i].F - X) % 2 == 1)) return cout << "First", 0;
				return cout << "Second", 0;
			}
			if (X < Y){
				if (abs(M[i].F - M[i].S) % 2 == 1) cout << "First";
				else cout << "Second";
				return 0;
			}else{
				cout << ((abs(M[i - 1].F - M[i - 1].S) % 2)?"First":"Second");
				return 0;
			}
		}
	}
	if (abs(M.back().F - M.back().S) % 2 == 1) cout << "First";
	else cout << "Second";
	return 0;
}
