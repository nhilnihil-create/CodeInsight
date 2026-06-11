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
	int a, b;
	cin >> a >> b;
	if (a >= 1) cout << "Positive" << endl;
	else if (a <= 0 && 0 <= b) cout << "Zero" << endl;
	else {
		int dif = b - a + 1;
		if (dif % 2 == 1) cout << "Negative" << endl;
		else cout << "Positive" << endl;
	}
	return 0;
}
