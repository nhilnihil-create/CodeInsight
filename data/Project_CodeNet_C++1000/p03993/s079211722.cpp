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
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep(i, n) {
        int a;
        cin >> a;
        --a;
        g[i].push_back(a);
    }
    int ans = 0;
    rep(i, n) {
        for ( auto v : g[i] ) {
            for ( auto u : g[v] ) {
                if ( u == i ) ++ans;
            }
        }
    }
    cout << ans / 2 << endl;
    return 0;
}
