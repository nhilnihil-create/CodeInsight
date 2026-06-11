#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	ll a, b, k;
	cin >> a >> b >> k;
	if (a == 0) {
		if (b == 0) {
			cout << 1 << endl;
		} else {
			cout << b / k + 1 << endl;
		}
	} else {
		cout << b / k - ((a - 1) / k) << endl;
	}
}