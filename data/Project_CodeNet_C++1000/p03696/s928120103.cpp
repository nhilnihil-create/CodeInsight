#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    string s;
    cin >> n >> s;
    int l = 0, r = 0;
    rep(i, n) {
        if (s[i] == '(') ++l;
        else if (l == 0) ++r;
        else             --l;
    }
    rep(i, r) s = '(' + s;
    rep(i, l) s += ')';
    cout << s << endl;
    return 0;
}
