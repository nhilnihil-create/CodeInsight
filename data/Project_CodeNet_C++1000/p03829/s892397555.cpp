#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <bitset>
#include <vector>
#include <queue>
#include <map>

#define i64 int64_t
#define ff(ii,nn,mm) for(int ii=nn;ii<mm;ii++)
#define sort(vvv) sort(vvv.begin(),vvv.end())
#define rvs(vvv) reverse(vvv.begin(),vvv.end())
int inf = 1000000007;

using namespace std;

int main() {
	i64 n, a, b;
	cin >> n >> a >> b;
	vector<i64> data(n);
	ff(i, 0, n) {
		cin >> data.at(i);
	}
	i64 ans = 0;
	ff(i, 0, n-1) {
		i64 c = (data.at(i + 1) - data.at(i)) * a;
		if (c > b) {
			ans += b;
		}
		else ans += c;
	}
	cout << ans << endl;
	return 0;
}