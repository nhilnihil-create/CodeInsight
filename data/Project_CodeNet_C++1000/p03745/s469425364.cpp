#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

int main() {
    int N; 
    cin >> N;
    int now = -1;
    int k = 2;
    int ans = 0;
    
    rep(i, N) {
        int a;
        cin >> a;
        if (a > now) {
            if (k == 2) {
                ans++;
                k = 0;
            }
            else if (k == 0) {
                k = 1;
            }
        }
        if (a < now) {
            if (k == 1) {
                ans++;
                k = 0;
            }
            else if (k == 0) {
                k = 2;
            }
        }
        now = a;
    }
    cout << ans;

    return 0;
}