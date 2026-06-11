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
int ret(int st, vvel &chi) {
	vel lis(0);
	rep(i, chi[st].size()){
		lis.push_back(ret(chi[st][i],chi));
	}
	sor(lis);
	int ans = 0;
	rep(i, chi[st].size()) {
		ans = max(ans, lis[i]) + 1;
	}
	return ans;
}
signed main() {
	int n; cin >> n;
	vel pa(n, -1);
	vvel chi(n);
	rep(i, n - 1) {
		cin >> pa[i + 1];
		pa[i + 1]--;
		chi[pa[i + 1]].push_back(i + 1);
	}
	cout << ret(0, chi) << endl;
	return 0;
}
