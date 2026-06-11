#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pf(n) printf("%d\n",n)
#define pff(a,b) printf("%d  %d\n",a,b);
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	
	sort(a.begin(), a.end());
	ll sum = 0;
	rep(i, n) sum += a[i];
	//pf(sum);
	for (int i = n - 1; i >= 0; i--) {
		sum -= a[i];
		//pff(sum, a[i]);
		if (a[i] > sum * 2) {
			pf(n - i);
			return 0;
		}
	}


	return 0;
}