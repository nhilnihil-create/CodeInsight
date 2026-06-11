#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <complex>
#include <set>
#include <list>
#include <iomanip>
#include <map>
#include <functional>
#include <string.h>

using namespace std;
static const double EPS = 1e-9;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a,0,sizeof(a))
#define minus(a) memset(a,0xff,sizeof(a))
#define chmax(a,b) a=min((a),(b))
#define chmin(a,b) a=max((a),(b))


#define MOD 1000000007

typedef pair<int,int>P;
#define INF (1LL<<61)

int n, m;
ll a[100005];
ll dat[200005];
ll sum[100005];
ll ans[100005];
ll res = INF;

int main(){
	scanf("%d %d ", &n, &m);
	rep(i, n) {
		scanf("%lld ", &a[i]); a[i]--;
	}
	rep(i, n-1) {
		if (a[i] < a[i+1]) {
			dat[a[i]+1]++;
			dat[a[i + 1]]--;
		}
		else {
			dat[a[i] + 1]++;
			dat[a[i + 1] + m]--;
		}
	}
	rep(i, 2 * m) {
		dat[i + 1] += dat[i];
	}
	rep(i, m) {
		dat[i] += dat[i + m];
	}
	rep(i, n-1) {
		sum[a[i + 1]] += (a[i + 1] + m - a[i]) % m - 1;//
	}
	
	rep(i, n-1) {
		if (a[i] > a[i + 1]) {
			ans[0] += 1 + a[i + 1];
		}
		else {
			ans[0] += a[i + 1] - a[i];
		}
	}
	FOR(i, 1, m) {
		ans[i] += sum[i-1];//
		ans[i] -= dat[i - 1];
		ans[i] += ans[i - 1];
	}
	rep(i, m) {
		res = min(res, ans[i]);
	}

	cout << res << endl;
	return 0;
}
