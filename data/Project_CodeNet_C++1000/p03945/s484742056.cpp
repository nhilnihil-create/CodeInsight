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

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int block_num = 1;
    rep(i, n-1) {
        if (s[i] != s[i+1]) {
            ++block_num;
        }
    }
    cout << block_num - 1 << endl;
    return 0;
}