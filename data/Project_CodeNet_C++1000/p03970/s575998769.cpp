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

    string x = "CODEFESTIVAL2016";

    int ans = 0;
    rep(i, 16) {
        if(s[i] != x[i]) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}