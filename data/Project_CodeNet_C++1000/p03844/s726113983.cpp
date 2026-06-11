#include <iostream>
#include <cassert>
#include <limits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <array>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cstring>
#include <bitset>
#include <stack>
#include <queue>

#define MOD (1e9 + 7);

using ll = int64_t;
using ull = uint64_t;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    char op;
    cin >> a; cin >> op; cin >> b;
    if (op == '+') {
        cout << a + b << endl;
    }
    else {
        cout << a - b << endl;
    }

    return 0;
}
