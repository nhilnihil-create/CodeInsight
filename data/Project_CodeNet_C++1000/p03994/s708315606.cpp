#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

string s;
llong k;

int main() {
    cin >> s >> k;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') continue;

        if (26 - (s[i] - 'a') <= k) {
            k -= 26 - (s[i] - 'a');
            s[i] = 'a';
        }

    }

    k %= 26;
    s.back() += k;

    cout << s << endl;

    return 0;
}
