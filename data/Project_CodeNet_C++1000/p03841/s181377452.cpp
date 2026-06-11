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
signed main() {
	int n; cin >> n;
	V<pin> x(n);
	rep(i, n) {
		int a; cin >> a; a--;
		x[i] = mkp(a, i);
	}
	sor(x);
	vvel ans(n);
	vel pq(0);
	rep(i, n) {
		rep(j, x[i].second) {
			pq.push_back(x[i].second);
		}
	}
	rep(i, n) {
		rep(j,n-1- x[i].second) {
			pq.push_back(x[i].second);
		}
	}
	int now_val = 0;
	auto itr = pq.begin();
	rep(i, n) {
		while (now_val < x[i].first) {
			int pla = *itr;
			if (ans[pla].size() == pla) { cout << "No" << endl; return 0; }
			ans[pla].push_back(now_val); now_val++;
			itr++;
		}
		int pla = x[i].second;
		if (ans[pla].size() < pla) { cout << "No" << endl; return 0; }
		ans[pla].push_back(x[i].first);
		now_val++;
	}
	while (now_val < n*n) {
		int pla = *itr;
		if (ans[pla].size() == pla) { cout << "No" << endl; return 0; }
		ans[pla].push_back(now_val);
		itr++;
		now_val++;
	}
	vel ret(n*n);
	rep(i, n) {
		rep(j, n) {
			ret[ans[i][j]] = i;
		}
	}
	cout << "Yes" << endl;
	rep(i, n*n-1) { cout << ret[i]+1<<" "; }
	cout << ret[n*n - 1]+1 << endl;
	return 0;
}
