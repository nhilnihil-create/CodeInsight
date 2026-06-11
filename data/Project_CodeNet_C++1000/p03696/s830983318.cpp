#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int bal = 0;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++bal;
        } else {
            --bal;
        }
        if (bal < 0) {
            mx +=  -bal;
            bal = 0;
        }
    }

    string res;
    res += string(mx, '(');
    res += s;
    if (bal > 0) {
        res += string(bal, ')');
    }

    cout << res << '\n';


    return 0;
}