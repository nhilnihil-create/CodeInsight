#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
	string a, b;
	cin >> a >> b;
	int p = a.size();
	int q = b.size();
	if (p > q) cout << "GREATER" << endl;
	else if (p < q) cout << "LESS" << endl;
	else {
		string ans = "EQUAL";
		rep(i, p) {
			int nowa = a[i] - '0';
			int nowb = b[i] - '0';
			if (nowa > nowb) {
				ans = "GREATER";
				break;
			}
			else if (nowb > nowa) {
				ans = "LESS";
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}