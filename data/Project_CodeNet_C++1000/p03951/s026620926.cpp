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
    string s, t;
    cin >> n >> s >> t;
    int idx = 0;
    for (int i = 1; i <= n; ++i) {
        if (s.substr(n-1-(i-1), i) == t.substr(0, i)) {
            idx = i;
        }
    }
    cout << n * 2 - idx << endl;
}
