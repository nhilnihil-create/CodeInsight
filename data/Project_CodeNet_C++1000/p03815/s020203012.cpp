#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)

int main() {
    ll x;
    cin >> x;
    ll ans = (x/11)*2; // 2回で11
    x %= 11;
    if (x > 6) {
        ans += 2;
    } else if (x > 0) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}