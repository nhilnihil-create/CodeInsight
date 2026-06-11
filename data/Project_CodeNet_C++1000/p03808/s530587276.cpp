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
#define INF 999999999
#define m0(x) memset(x,0,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define p(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define int long long


using namespace std;


int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int dxx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dyy[8] = { 1,-1,0,1,-1,0,1,-1 };




ll gcd(ll x, ll y) {
	ll m = max(x, y), n = min(x, y);
	if (m%n == 0)return n;
	else return gcd(m%n, n);
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y)*y;
}

ll myPow(ll x, ll n, ll m) {
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return myPow(x * x % m, n / 2, m);
	else
		return x * myPow(x, n - 1, m) % m;
}

ll pow2(ll a, ll n) {//aのn乗を計算します。
	ll x = 1;
	while (n > 0) {//全てのbitが捨てられるまで。
		if (n & 1) {//1番右のbitが1のとき。
			x = x * a;
		}
		a = a * a;
		n >>= 1;//bit全体を右に1つシフトして一番右を捨てる。
	}
	return x;
}

long long nCr(int n, int r) {
	if (r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
	long long ans = 1;
	int i;

	for (i = 1; i <= r; i++) {
		ans *= n - r + i;
		ans /= i;
	}

	return ans;
}


const int MOD = 1000000007;

bool arr[1050000];
int sosuu[100010];
void Eratosthenes() {
	ll N = 1050000;
	int c = 0;
	for (int i = 0; i < N; i++) {
		arr[i] = 1;
	}
	for (int i = 2; i < sqrt(N); i++) {
		if (arr[i]) {
			for (int j = 0; i * (j + 2) < N; j++) {
				arr[i *(j + 2)] = 0;
			}
		}
	}

	for (int i = 2; i < N; i++) {
		if (arr[i]) {
			sosuu[c] = i;
			//cout << sosuu[c] << " ";
			c++;
		}
	}
	//cout << endl;
	//cout << c << endl;
}


vector<int> graph[100010];
int a[100010];
int d[100010];
signed main() {
	int K;
	int N; cin >> N;
	ll sum = 0;
	REP(i, N) {
		cin >> a[i];
		sum += a[i];
	}
	if (2 * sum % (N*(N + 1)) != 0) {
		p("NO");
		return 0;
	}
	K = 2*sum / (N*(N+1));
	d[N - 1] = a[0] - a[N - 1];
	REP(i, N - 1) {
		d[i] = a[i + 1] - a[i];
	}
	bool ok = true;
	REP(i, N) {
		if (d[i] > K) {
			ok = false;
			break;
		}
		if ((K - d[i]) % N != 0) {
			ok = false;
			break;
		}
	}
	if (ok) {
		p("YES");
	}
	else p("NO");
}