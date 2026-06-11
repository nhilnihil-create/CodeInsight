#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<stack>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	rep(i, n - m + 1)rep(j, n - m + 1) {
		bool flag = true;
		rep(k, m)rep(l, m) {
			if (a[i + k][j + l] != b[k][l]) flag = false;
		}
		if (flag) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}