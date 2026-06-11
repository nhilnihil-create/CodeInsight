#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int i, o, t, j, l, s, z;
    cin >> i >> o >> t >> j >> l >> s >> z;
    long long int res = 0;
    if (i % 2 + l % 2 + j % 2 >= 2 && i > 0 && l > 0 && j > 0) {
        i--, l--, j--;
        res += 3;
    }
    res += i / 2 * 2;
    res += j / 2 * 2;
    res += l / 2 * 2;
    res += o;
    cout << res << endl;
}


