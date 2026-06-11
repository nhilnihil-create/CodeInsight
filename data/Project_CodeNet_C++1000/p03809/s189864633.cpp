#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<functional>
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
int kai_size = 100001;
vel kai(kai_size, 1);
vel ink(kai_size, 1);

int RE() {
	vel v(3, 2);
	return v.at(4);
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
int ret(int now, vvel &chi,vel &a) {
	int mx = 0;
	int sum = 0;
	if (chi[now].size() == 0) { return a[now]; }
	if (chi[now].size() == 1) {  
		int val = ret(chi[now][0], chi, a);
		if (val == a[now]) { return val; }
		return -1;
	}
	rep(i, chi[now].size()) {
		int nex = chi[now][i];
		int val = ret(nex, chi, a);
		if (val < 0) { return -1; }
		sum += val;
		mmax(mx, val);
	}
	if (a[now] < mx) { return -1; }
	if (sum > a[now] * 2) { return -1; }
	if (sum < a[now]) { return -1; }
	return a[now] * 2 - sum;
}
signed main() {
	int n; cin >> n;
	vel a(n);
	rep(i, n) { cin >> a[i]; }
	if (n == 2) {
		if (a[0] == a[1]) { cout << "YES" << Endl; return 0; }
		cout << "NO" << endl;
		return 0;
	}
	vel st(n - 1), to(n - 1);
	vvel way(n);
	rep(i, n-1) {
		cin >> st[i] >> to[i];
		st[i]--; to[i]--;
		way[st[i]].push_back(to[i]);
		way[to[i]].push_back(st[i]);
	}
	int start = 0;
	if (way[0].size() == 1) {
		start = way[0][0];
	}
	vel dist = dis(start, way);
	vvel chi(n);
	rep(i, n - 1) {
		if (dist[st[i]] + 1 == dist[to[i]]) {
			chi[st[i]].push_back(to[i]);
		}
		else {
			chi[to[i]].push_back(st[i]);
		}
	}
	int val = ret(start, chi, a);
	if (val == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
