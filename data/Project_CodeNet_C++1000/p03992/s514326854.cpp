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
    string s;
    cin >> s;
    string first = s.substr(0, 4);
    string second = s.substr(4, 8);
    cout << first << " " << second << endl;
    return 0;
}
