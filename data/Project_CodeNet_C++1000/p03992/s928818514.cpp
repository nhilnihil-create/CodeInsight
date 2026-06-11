#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;

    string ans;
    rep(i, 4) {
        ans.push_back(s[i]);
    }
    ans.push_back(' ');
    for(int i = 4; i < 12; i++) {
        ans.push_back(s[i]);
    }

    cout << ans << endl;
    return 0;
}