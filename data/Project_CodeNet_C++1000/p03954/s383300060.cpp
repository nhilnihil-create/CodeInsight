#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define rep(x, l, r) for(int x = l; x <= r; x++)
#define repd(x, r, l) for(int x = r; x >= l; x--)
#define clr(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define MAXN 200005
#define fi first
#define se second
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 1 << 30;
const int p = 1000000007;
int lowbit(int x){ return x & (-x);}
int fast_power(int a, int b){ int x; for(x = 1; b; b >>= 1){ if(b & 1) x = 1ll * x * a % p; a = 1ll * a * a % p;} return x % p;}

int n;
int a[MAXN], b[MAXN];

bool check(int mid){
	int res = 0, minx = INF;
	rep(i, 1, 2 * n - 1) b[i] = a[i] >= mid;
	rep(i, 1, 2 * n - 1)
		if(b[i] == b[i + 1]){
			if(min(abs(n - i), abs(n - (i + 1))) < minx){
				minx = min(abs(n - i), abs(n - (i + 1)));
				res = b[i];
			}
		}
	if(minx == INF) return (n & 1) == b[n];
	return res;
}

int main(){
	//freopen("pyramid.in", "r", stdin);
	//freopen("pyramid.out", "w", stdout);
	scanf("%d", &n);
	rep(i, 1, 2 * n - 1) scanf("%d", &a[i]);
	int l = 0, r = 2 * n - 1, ans;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	} 
	printf("%d\n", ans);
    return 0;
}