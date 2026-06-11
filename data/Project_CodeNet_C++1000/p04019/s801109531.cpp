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
    string s;
    cin >> s;
    int h_cnt = 0;
    int w_cnt = 0;
    int n = s.size();
    bool flg[4] = {false, false, false, false};
    rep(i, n) {
        if (s[i] == 'N') flg[0] = true;
        if (s[i] == 'E') flg[1] = true;
        if (s[i] == 'W') flg[2] = true; 
        if (s[i] == 'S') flg[3] = true;
    }
    if (!(flg[0] ^ flg[3]) && !(flg[1] ^ flg[2])) cout << "Yes" << endl;
    else                                          cout << "No" << endl;
    return 0;
}
