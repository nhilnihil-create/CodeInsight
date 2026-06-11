#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;

int main(void) {
    UInt a, b, x;
    cin >> a >> b >> x;
    UInt answer;
    if (a == 0) {
        answer = b / x + 1;
    } else {
        answer = b / x - (a - 1) / x;
    }
    cout << answer << endl;
    return 0;
}

