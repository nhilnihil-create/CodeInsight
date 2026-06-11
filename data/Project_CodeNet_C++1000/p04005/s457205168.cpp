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
    ll a, b, c;
    cin >> a >> b >> c;
    if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << min({a * b, b * c, c * a}) << endl; 
    return 0;
}
