#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
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
#define end_program(s) cout << s <<endl;return 0
int kai_size = 120001;
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
V<pin> uni(V<pin> &v) {
	sor(v);
	V<pin> ans(1, v[0]);
	for (int i = 1; i < v.size(); i++) {
		if (v[i] != v[i-1]) { ans.push_back(v[i]); }
	}
	v = ans;
	return v;
}
int s_gcd(int a, int b) {
	if (b == 0) { return a; }
	return s_gcd(b, a%b);
}
int gcd(int a, int b) {
	if (a < b) { swap(a, b); }
	return s_gcd(a, b);
}
signed main() {
	int n, l, t; cin >> n >> l >> t; t *= 2;
	vel stay;
	vel move;
	int p0 = -1;
	rep(i, n) {
		int x, w; cin >> x >> w;
		if (w == 1) { stay.push_back(x); if (p0 == -1) { p0 = i; } }
		else { move.push_back(x); }
	}
	if (stay.size() == 0) {
		rep(i, n) {
			cout << per(move[i] - t / 2, l) << endl;
		}
		return 0;
	}
	int c0 = stay[0];
	rep(i, stay.size()) {
		stay[i] = per(stay[i] - c0, l);
	}
	rep(i, move.size()) {
		move[i] = per(move[i] - c0, l);
	}
	sor(stay);
  	sor(move);
	int ind = move.size();
	ind *= t / l;
	int ext = t % l;
	ind += (lower_bound(move.begin(), move.end(), ext) - move.begin());
	ind = per(-ind, n);
	vel ans;
	for (auto x : stay) {
		ans.push_back(x);
	}
	for (auto x : move) {
		ans.push_back(per(x - t, l));
	}
	sor(ans);
	t = t / 2;
	rep(i, n) {
		cout << (ans[(i + ind+n-p0) % n]+t+c0)%l << endl;
	}
	return 0;
}
