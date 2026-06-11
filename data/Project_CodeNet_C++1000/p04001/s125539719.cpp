#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SIZE = 2 * 1e5 + 10, MOD = 1e9 + 7, INF = 1e9;

ll dp[SIZE], lst[SIZE][26];

int main() {
    fastInp;

    string s;
    cin >> s;

    ll pw = (1ll << (s.size() - 1));
    ll sm = 0;
    for (int i = 0; i < pw; i++) {
        ll curS = 0, cr = 0;
        for (int j = 0; j < s.size(); j++) {
            cr *= 10;
            cr += s[j] - '0';
            if ((i >> j) & 1) {
                curS += cr;
                cr = 0;
            }
            
        }
        sm += curS + cr;
    }
    cout << sm;
    return 0;
}
