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
#include<limits.h>
#include<cassert>
#include <fstream>
#include <time.h>
#include <iterator>
#include<random>



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
int MOD = (ll)1000000000 + 7;
const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;
typedef pair<int, int>P;
const int MAX = 500050;


int N, M;
int A[100010], B[100010], C[100010];
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	FOR(i,1, N+1) {
		cin >> A[i];
	}
	FOR(i, 1, N) {
		int s = A[i], t = A[i + 1];
		if (s < t) {
			B[0] += t - s, B[s + 1] -= t - s;
			B[s + 1] += 1 + t, B[t + 1] -= 1 + t;
			C[s + 1] -= 1, C[t + 1] += 1;
			B[t + 1] += t - s, B[M + 1] -= t - s;
		}
		else {
			B[t + 1] += t + M - s; B[s + 1] -= t + M - s;
			B[s + 1] += 1 + t + M; B[M + 1] -= 1 + t + M;
			C[s + 1]--, C[M + 1]++;
			B[0] += 1 + t; B[t + 1] -= 1 + t;
			C[0]--; C[t + 1]++;
		}
		/*REP(i, M + 1) {
			pe(B[i]);
		}cout << endl;*/
	}
	FOR(i,1, M + 1) {
		B[i] += B[i - 1];
		C[i] += C[i - 1];
	}
	FOR(i, 1, M + 1) {
		C[i] *= i;
	}
	/*FOR(i, 1, M + 1) {
		pe(C[i]);
	}cout << endl;*/
	int ans = INF;
	FOR(i, 1, M + 1) {
		//pe(B[i]);
		ans = min(ans, B[i] + C[i]);
	}
	//cout << endl;
	print(ans);
}
