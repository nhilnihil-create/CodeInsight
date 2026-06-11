#include <bits/stdc++.h>
  
using namespace std;
  
template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }
  
#define pb push_back
#define mp make_pair
#define cotu cout
#define itn int
#define Red ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n - 1; i >= 0; --i)
#define Rep(i, a, n) for(int i = (a); i <=(n); ++i)
#define repst(i, n) for(auto it = n.begin(); it != n.end(); ++it)
#define Repr(i, a, n) for(int i = (n); i >= (a); --i)
#define setp(x) fixed << setprecision(x)
#define ordered_set tree<int , null_type,less<int >, rb_tree_tag,tree_order_statistics_node_update> 
  
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
  
const int inf = int(1e9);
const int mod = inf + 7;
const int N = 1e6 + 555; // TL MB
const double PI = acos(-1.0);
void mul(ll &x, ll y){
	x *= y;
	if(x >= mod) x %= mod;
}
 
void add(ll &x, ll y){
	x += y;
	if(x >= mod) x -= mod;
	if(x < 0) x += mod;
}
ll bp(ll a, ll n){
	ll r = 1;
	while(n){
		if(n & 1) mul(r, a);
		mul(a, a);
		n >>= 1;
	}
 
}
vector<vector<int> > u(3001, vector<int> (3001));

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dz[] = {'U', 'D', 'R', 'L'};
string bfs(int x, int y, int px, int py){
	vector<vector<pii> > path(3001, vector<pii> (3001));
	vector<vector<int> > curu = u;
	queue<pii> q;
	q.push({x, y});
	curu[x][y] = 1;
	curu[px][py] = 0;
	while(!q.empty()){
		pii u = q.front();
		q.pop();
		rep(i, 4){
			int qx = u.F + dx[i], qy = u.S + dy[i];
			if(qx >= 0 && qx <= 3000 && qy >= 0 && qy <= 3000 && !curu[qx][qy]) {
				curu[qx][qy] = 1;
				q.push({qx, qy});
				path[qx][qy] = {u.F, u.S};
			}
		}
	}
	// return "1";
	string ans = "";
	while(mp(px, py) != mp(x, y)){
		u[px][py] = 1;
		int cx = px - path[px][py].F;
		int cy = py - path[px][py].S;
		rep(i, 4) if(cx == dx[i] && cy == dy[i]) ans += dz[i];
		tie(px, py) = path[px][py];
	}
	reverse(all(ans));
	return ans;
}
void solve()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x1 += 1500, y1 += 1500, x2 += 1500, y2 += 1500;
	string ans1 = bfs(x1, y1, x2, y2);
	string ans2 = bfs(x2, y2, x1, y1); 
	string ans3 = bfs(x1, y1, x2, y2);
	string ans4 = bfs(x2, y2, x1, y1);
	cout << ans1 << ans2 << ans3 << ans4;
}	 

 
int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    Red;
  	int T = 1;
  	// cin >> T;
  	for(int i = 1; i <= T; ++i){
  		solve();
  	}
  	return 0;

}