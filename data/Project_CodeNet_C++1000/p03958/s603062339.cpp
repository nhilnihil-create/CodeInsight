#include <iostream>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n;i++)
int main() {
	int k, t,a;cin >> k >> t;
	priority_queue<int> pq;
	rep(i, t) {
		cin >> a;
		pq.push(a);
	}
	cout << max(2 * pq.top() - 1 - k, 0) << endl;
}