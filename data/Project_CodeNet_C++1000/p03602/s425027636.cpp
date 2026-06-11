#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
using namespace std;
#define _GLIBCXX_DEBUG
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pii pair<long long,long long>
#define ppii pair<long long,pair<long long,long long>>
#define all(x) (x).begin(),(x).end()
#define rep(x) for(int i = 0;i < (x);i++)
#define repj(x) for(int j = 0;j < (x);j++)
#define REP(i,x) for(int (i) = 0;(i) < (x);(i)++)
#define rrep(x) for(int i = (x);i >= 0;i--)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define mod 1000000007
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define pyes cout << "Yes" << endl
#define pno cout << "No" << endl
typedef vector<vector<long long>> vii;
typedef long long lint;
typedef long long ll;
lint qp(int a, ll b) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
lint qp(int a, ll b, int mo) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
lint gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
long long INF = 1e14;
const int MAX_N = 1 << 17;
const int cf = 100010;
///////////////////////////////////////////////////////////////////////////////
lint grid[301][301];
int main(void) {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}

	ll ans = 0;

	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			bool flag = true;
			for (int k = 0; k < n; k++)
			{
				if (k == i || k == j) continue;
				if (grid[i][k] + grid[k][j] < grid[i][j]) {
					printf("-1\n"); return 0;
				}
				if (grid[i][k] + grid[k][j] == grid[i][j]) {
					flag = false; 
					break;
				}
			}
			if (flag) ans += grid[i][j];
		}
	}

	cout << ans << endl;
	return 0;
}
