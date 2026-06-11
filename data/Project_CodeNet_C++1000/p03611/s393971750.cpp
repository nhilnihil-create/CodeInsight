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
    cin >> n;
    vector<int> cnt(1e5+1);
    rep(i, n) {
        int a;
        cin >> a;
        ++cnt[a];
        ++cnt[a+1];
        if (a-1>=0) ++cnt[a-1];
    }
    int max_num = 0;
    int ans = 0;
    rep(i, 1e5+1) {
        if (cnt[i] > max_num) {
            ans = i;
            max_num = cnt[i];
        }
    }
    cout << max_num << endl;
    return 0;
}
