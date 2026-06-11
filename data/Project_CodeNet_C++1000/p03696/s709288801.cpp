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
    int n;
    cin >> n;
    string s, res;
    cin >> s;
    int c = 0;
    int r = 0;
    for (int i = 0; i < n; i++) {
        c += (s[i] == '(' ? 1 : -1);
        r = max(r, -c);
    }
    res = string(r, '(') + s;
    c += r;
    while (c > 0) {
        c--;
        res.push_back(')');
    }
    cout << res << endl;
}
