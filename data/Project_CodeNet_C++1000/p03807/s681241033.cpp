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
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    ll cnt = 0;
    rep(i, n) {
        ll a;
        cin >> a;
        if ( a&1 ) ++cnt;
    }
    cout << ((cnt&1) ? "NO" : "YES") << endl;
    return 0;
}
