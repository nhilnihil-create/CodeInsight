#include <iostream>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n;i++)
int main() {
	ll q, h, s, d, n,p[4],sum =0;cin >> q >> h >> s >> d >> n;
	if (n == 1) {
		q = min(q * 4, h * 2);
		cout << min(q, s)<< endl;
	}
	else {
		p[0] = 8 * q, p[1] = h * 4, p[2] = s * 2;p[3] = d;
		sort(p, p + 4);
		sum = (n / 2) * p[0];
		q = min(q * 4, h * 2);
		sum += min(q, s) * (n % 2);
		cout << sum << endl;
	}
}