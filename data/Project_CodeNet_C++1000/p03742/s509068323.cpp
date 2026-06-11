#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main() {
    ll x, y;
    cin >> x >> y;
    if (abs(x-y) <= 1) cout << "Brown" << endl;
    else cout << "Alice" << endl;



    return 0;
}
