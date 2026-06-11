#include <iostream>
#include <vector>
#include<algorithm>
#include<map>
#include<cmath>
#include<set>
using namespace std;
#define rep(i,n) for(int i =0;i < n;i++)
int main() {
	int n, a, b, ans = 0;cin >> n;
	vector<pair<int, int>> v(n);
	rep(i, n) {
		cin >> a >> b;
		v[i] = make_pair(a, b);
	}
	sort(v.begin(), v.end());
	cout << v[n - 1].first + v[n - 1].second << endl;
 }