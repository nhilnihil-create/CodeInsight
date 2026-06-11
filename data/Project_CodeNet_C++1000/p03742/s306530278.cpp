#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <map>
#include <stack>
#include <map>
#include <unordered_map>
#define REP(i,n) for(long (i)=0;(i)<(n);(i)++)
#define REPI(i,a,b) for(long (i)=(a);(i)<(b);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 1e9 + 7;
using namespace std;
using P = pair<long, long>;
using VI = vector<long>;

int main() {
    long x, y;
    cin >> x >> y;
    if (abs(x - y) <= 1) {
        cout << "Brown" << endl;
    } else {
        cout << "Alice" << endl;
    }
}
