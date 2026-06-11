#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	string o, e;
	cin >> o >> e;
	string pass = "";
	
		rep(i, e.size()) {
			pass += o[i];
			pass += e[i];
		}
	
	if (o.size() > e.size()) pass += o.back();
	cout << pass << endl;
	return 0;
}