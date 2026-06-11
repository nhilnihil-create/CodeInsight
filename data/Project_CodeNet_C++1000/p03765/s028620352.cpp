#include <bits/stdc++.h>
using namespace std;

#define name ""
#define ini freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
#define foe(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define long long long 
#define db double 
#define pii pair <int, int>
#define pll pair <long, long>
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1e9+7;
const int MOD = 1e9+7;
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

const int N = 1e5+1;
int F[N], G[N];
string S, T;

int main()
{
	fastio;
	cin >> S >> T;
	for (int i = 0; i < S.size(); i++){
		F[i + 1] = F[i] + S[i] - 'A' + 1;
	}
	for (int i = 0; i < T.size(); i++){
		G[i + 1] = G[i] + T[i] - 'A' + 1;
	}
	int n; cin >> n;
	while (n--){
		int a, b, c, d; 
		cin >> a >> b >> c >> d;
		int x = F[b] - F[a - 1];
		int y = G[d] - G[c - 1];
		if ((x % 3) == (y % 3)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}