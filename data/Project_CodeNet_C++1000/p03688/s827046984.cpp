//g++ main.cpp -I /usr/local/include/ac-library
#include<cmath>
//#include <atcoder/all>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
//using namespace atcoder;
stack<int> st;
queue<int> qu;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
#define ALL(a) a.begin(), a.end()
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define pb push_back
#define sz(x) (int)(x).size()
#define mod 1000000007
//#define mint=modint1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
deque<int> deq;
#define fi first
#define se second
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
typedef pair<int, int> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int n, x, y, z;
int a[100000];
int main() {
	scanf("%d", &n);
	x = n;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		if (a[i] < x)x = a[i];
		if (a[i] > y)y = a[i];
	}
	if (y - x > 1) {
		printf("No\n");
		return 0;
	}
	if (y == x) {
		if (y == n - 1)printf("Yes\n");
		else if (y <= n / 2)printf("Yes\n");
		else printf("No\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == x)z++;
	}
	if (z < y && y <= z + (n - z) / 2)printf("Yes\n");
	else printf("No\n");
    return 0;
}
