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
    ll a, b, x;
    cin >> a >> b >> x;
    ll numb = b / x;
    if (a == 0) {
        cout << numb + 1LL << endl;
    }
    else {
        cout << numb - (a - 1LL) / x << endl;
    }
    return 0;
}
