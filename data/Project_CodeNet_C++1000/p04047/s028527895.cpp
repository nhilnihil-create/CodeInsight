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
	int n;cin >> n;vector<int> l(2 * n);
	rep(i, 2 * n) cin >> l[i];
	sort(l.begin(), l.end());
	int sum = 0;
	rep(i, n) sum += l[2 * i];
	cout << sum << endl;
}