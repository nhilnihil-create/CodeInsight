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
	int n;
	cin >> n;
	int p = 0;
	vector<int> data(n);
	ff(i, 0, n) {
		cin >> data.at(i);
	}
	sort(data);
	ff(i, 1, n) {
		if (data.at(i - 1) == data.at(i))p++;
	}
	int ans = n;
	while (p>0) {
		ans -= 2;
		p -= 2;
	}
	cout << ans << endl;
	return 0;
}