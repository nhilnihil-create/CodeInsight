#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

const int MAX = 500010;
const int MOD = (ll)1e9 + 7;
const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;

typedef pair<int, int>P;

int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };


int num[8];
signed main() {
	REP(i, 7) {
		cin >> num[i];
	}
	//print(-1 / 2 * 2);
	int ans = 0;
	ans += num[1];
	if (num[3] % 2 == 1 && num[4] % 2 == 1) {
		if (num[0] > 0) {
			ans += 3;
			num[0]--; num[3]--; num[4]--;
		}
	}
	int B = (num[0] / 2) * 2;
	ans += B;
	num[0] -= B;
	int ans2 = ans;
	if (num[0] == 1) {
		if (num[3] % 2 == 1 || num[4] % 2 == 1) {
			if (num[3] > 0 && num[4] > 0) {
				ans2 += 3;
				ans2 += (num[3] - 1) / 2 * 2 + (num[4] - 1) / 2 * 2;
				print(ans2);
				return 0;
			}
			ans2 += num[3] / 2 * 2 + num[4] / 2 * 2;
			print(ans2); return 0;
		}
		else {
			ans2 += num[3] + num[4];
			print(ans2); return 0;
		}
	}
	else {
		ans2 += num[3] / 2 * 2 + num[4] / 2 * 2;
		print(ans2);
		return 0;
	}
	int A = min(num[0], min(num[3], num[4]));
	ans += A*3;
	num[0] -= A; num[3] -= A; num[4] -= A;
	ans += min(num[3], num[4])*2;
	print(ans);
	//print(-1 / 2 * 2);
}	
