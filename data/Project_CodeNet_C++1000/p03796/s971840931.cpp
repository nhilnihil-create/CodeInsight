#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9

int main(){
    ll n;
    cin >> n;
    ll ans = 1;
    for (ll i = 1; i <= n; i++) {
        ans *= i;
        ans %= 1000000007;
    }

    cout << ans << endl;

    return 0;
}