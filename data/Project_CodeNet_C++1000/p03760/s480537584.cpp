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
const int INF = 1001001001;

int main() {
    string o, e;
    cin >> o >> e;
    int n = o.size();
    int m = e.size();
    if ((n+m) % 2 == 0) {
        rep(i, n) cout << o[i] << e[i];
        cout << endl;
    }
    else {
        rep(i, m) cout << o[i] << e[i];
        cout << o[n - 1] << endl;
    }
 	return 0;
}