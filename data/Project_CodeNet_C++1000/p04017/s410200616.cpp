#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<functional>
#include<unordered_map>
using namespace std;
int p = 1000000007;
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define rep(i,n) for(long long i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define V vector
#define Endl endl
#define veb vector<bool>
#define sq(a) (a)*(a)
#define rev(s) reverse(s.begin(),s.end())
#define end_pr(s) cout << s <<endl;return 0
#define itn int
#define bs bitset<5001>
int kai_size = 1000001;
vel kai(kai_size, 1);
vel ink(kai_size, 1);
vel dist;
int RE() {
	vel v(3, 2);
	return v.at(4); 
}
int ru(int a, int r) {
	if (r == 0) { return 1; }
	int ans = ru(a, r / 2);
	ans *= ans; ans %= p;
	if (r % 2 == 1) { ans *= a; }
	return ans % p;
}
int inv(int a) {
	return ru(a, p - 2);
}
void make_kai() {
	rep(i, kai_size-1) { kai[i + 1] = (kai[i] * (i + 1)) % p; }
	rep(i, kai_size) { ink[i] = inv(kai[i]); }
}
int com(int n, int r) {
	if (r < 0 || n < r) { return 0; }
	int ans = kai[n] * ink[r];
	ans %= p; ans *= ink[n - r]; ans %= p;
	return ans;
}
vel dis(int mid1, vvel &way) {
	int n = way.size();
	vel dist(n, -1); dist[mid1] = 0;
	queue<int> q;
	q.push(mid1);
	while (!q.empty()) {
		int st = q.front(); q.pop();
		rep(i, way[st].size()) {
			int to = way[st][i];
			if (dist[to] == -1) {
				dist[to] = dist[st] + 1;
				q.push(to);
			}
		}
	}
	return dist;
}
pin most_far(int now, int n, vvel &way) {
	vel dist1 = dis(now, way);
	pin ans = mkp(-1, 0);
	rep(i, n) {
		if (dist1[i] > ans.first) { ans = mkp(dist1[i], i); }
	}
	return ans;
}

int per(int a, int b) {
	int ans = a % b;
	if (ans < 0) { ans += b; }
	return ans;
}
vel uni(vel v) {
	sor(v);
	vel ans(1, v[0]);
	for (int i = 1; i < v.size(); i++) {
		if (v[i] != v[i-1]) { ans.push_back(v[i]); }
	}
	return ans;
}
int s_gcd(int a, int b) {
	if (b == 0) { return a; }
	return s_gcd(b, a%b);
}
int gcd(int a, int b) {
	if (a < b) { swap(a, b); }
	return s_gcd(a, b);
}
bool is_prime(int i) {
	for (int j = 2; j*j <= i; j++) {
		if (i%j == 0) { return false; }
	}
	return true;
}
int get(int i, int j, vvel &ans) {
	int n = ans.size();
	if (i < 0 || n <= i || j < 0 || n <= j) { return 1; }
	return ans[i][j];
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
void del(vel &v, int a) {
	vel ans;
	for (auto x : v) {
		if (x != a) { ans.push_back(x); }
	}
	v = ans;
}
void sz_tree(int ce0, V<V<pin>> &chi,vel &sz) {
	for (auto x : chi[ce0]) {
		sz_tree(x.first, chi, sz);
		sz[ce0] += sz[x.first];
	}
}
int ord(int n) {
	if (n % 2 == 1) { return 0; }
	return 1 + ord(n / 2);
}
int get(int st_val, int dif_val, int st_pla, int to_pla, vel &sum,vel &dsum) {
	int ans = st_val * (sum[to_pla] - sum[st_pla]);
	int pl = dsum[to_pla] - dsum[st_pla] - st_pla * (sum[to_pla] - sum[st_pla]);
	pl *= dif_val;
	return ans + pl;
}
signed main() {
	int n; cin >> n;
	vel x(n);
	rep(i, n) { cin >> x[i]; }
	int l; cin >> l;
	vvel next(17, vel(n));
	rep(i, n) {
		next[0][i] = upper_bound(x.begin(), x.end(), x[i] + l) - x.begin();
		next[0][i]--;
	}
	for (int i = 1; i < 17; i++) {
		rep(j, n) {
			next[i][j] = next[i - 1][next[i - 1][j]];
		}
	}
	int q; cin >> q;
	rep(i, q) {
		int a, b; cin >> a >> b;
		a--; b--;
		if (a > b) { swap(a, b); }
		int now_day = 0; int now_pla = a;
		for (int i = 16; i >= 0; i--) {
			if (next[i][now_pla] < b) {
				now_pla = next[i][now_pla];
				now_day += (1 << i);
			}
		}
		now_day++;
		cout << now_day << endl;
	}
	return 0;
}
/*18:45:00*/