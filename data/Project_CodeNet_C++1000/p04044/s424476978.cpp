#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
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
    Int n, l;
    cin >> n >> l;
    vector<string> s(n);
    for (Int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    string result = "";
    for (Int i = 0; i < n; ++i) {
        result += s[i];
    }
    cout << result << endl;
    return 0;
}
