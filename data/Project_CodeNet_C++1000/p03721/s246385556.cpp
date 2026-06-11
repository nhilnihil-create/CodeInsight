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
#include<string.h>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

int main() {
	int n;
  ll k;
	cin >> n >> k;
	vector<pair<int, int>> a(n);
	rep(i, n) cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end());
	ll cnt = 0;
	rep(i, n) {
		cnt += (ll)a[i].second;
		if (cnt >= k) {
			cout << a[i].first << endl;
			return 0;
		}
	}
}
