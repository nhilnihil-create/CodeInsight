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
#include<map>
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
#define qin pair<pin,int>
#define V vector
#define Endl endl
#define veb vector<bool>
#define sq(a) (a)*(a)
#define rev(s) reverse(s.begin(),s.end())
#define end_pr(s) cout << s <<endl;return 0
#define itn int
#define bs bitset<5001>
#define mk_re(a) if(a){RE();}
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
int msb(int l) {
	if (l == 1) { return 0; }
	return 1 + msb(l / 2);
}
int rui_2(int a) {
	if (a == 0) { return 1; }
	return 2 * rui_2(a - 1);
}
signed main() {
	int n; cin >> n;
	vel a(n);
	vel bac(n);
	int max1 = 0;
	string t = "Impossible";
	rep(i, n) { cin >> a[i]; bac[a[i]]++; mmax(max1, a[i]); }
	int sma = (max1 + 1) / 2;
	if (max1 % 2 == 0) {
		if (bac[sma] != 1) { end_pr(t); }
		for (int i = sma + 1; i <= max1; i++) {
			if (bac[i] < 2) { end_pr(t); }
		}
	}
	else {
		if (bac[sma] != 2) { end_pr(t); }
		for (int i = sma+1; i <= max1; i++) {
			if (bac[i] < 2) { end_pr(t); }
		}
	}
	cout << "Possible" << endl;
	return 0;
}
/*
11:23~

*/