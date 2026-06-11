#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
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
#define mod 1000000007
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
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

int main(void) {
	int n; cin >> n;
	string s; cin >> s;
	vector<int> a(n);
	int da[2] = { 1,-1 };
	int db[2] = { 1, - 1 };
	vector<int> lyn(n);
	rep(n) {
		if (s[i] == 'o') lyn[i] = 1;
		else lyn[i] = -1;
	}
	for (int p = 0; p < 2; p++) {
		for (int q = 0; q < 2; q++) {
			a[0] = da[p], a[1] = da[q];
			for (int i = 2; i < n ; i++) {
				a[i] = a[i - 2] * a[i - 1] * lyn[i-1];
			}
			if (a[0] == a[n - 1] * a[n - 2] * lyn[n - 1] && a[1] == a[0] * a[n - 1] * lyn[0]) {
				for (int i : a) {
					if (i == 1) cout << 'S'; else cout << 'W';
				}
				cout << endl;
				return 0;
			}
			else continue;
		}
	}
	cout << -1 << endl;
	return 0;
}