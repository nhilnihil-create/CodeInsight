#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) v.erase(unique(v.begin(), v.end()), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;

#define MAX_V 1000000

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	ll a[3 * N];
	rep(i, 0, 3 * N) cin >> a[i];

	priority_queue<ll> q1, q2;
	ll res1[N + 1], res2[N + 1];
	memset(res1, 0, sizeof(res1));
	memset(res2, 0, sizeof(res2));
	ll prev1 = 0, prev2 = 0;
	rep(i, 0, N) {
		q1.push(-a[i]);
		res1[0] += a[i];
		q2.push(a[3 * N - i - 1]);
		res2[0] += a[3 * N - i - 1];
	}


	ll res = 0;
	rep(k, N, 2 * N) {
		q1.push(-a[k]);
		ll tmp1 = q1.top();
		q1.pop();
		res1[k - N + 1] = res1[k - N] + tmp1 + a[k];
		
		q2.push(a[3 * N - k - 1]);
		ll tmp2 = q2.top();
		q2.pop();
		res2[k - N + 1] = res2[k - N] - tmp2 + a[3 * N - k - 1];
	}
	
	res = res1[0] - res2[N];

	rep(i, 1, N + 1) res = max(res, res1[i] - res2[N - i]);
	cout << res << endl;

}
