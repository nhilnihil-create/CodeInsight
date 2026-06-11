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
    int n, l;
    cin >> n >> l;
    vector<string> sv(n);
    rep(i, n) cin >> sv[i];
    sort(sv.begin(), sv.end());
    rep(i, n) {
        cout << sv[i];
    }
    cout << endl;
    return 0;
}
