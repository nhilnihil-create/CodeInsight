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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(a.rbegin(), a.rend());
	int ans = 0;
	rep(i, k) ans += a[i];
	cout << ans << endl;
}