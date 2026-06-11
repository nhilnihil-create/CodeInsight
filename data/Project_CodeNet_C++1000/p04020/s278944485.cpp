#include<bits//stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int ll;
ll x,x2,y2,n,k,sum = 0,pre = 0; string s;
int main() {
	cin >> n; vector<ll> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n) {
		sum += a[i] / 2;
		if (i < n - 1 && a[i] & 1 && a[i + 1] > 0) sum++, a[i + 1]--;
	}cout << sum << endl;
}