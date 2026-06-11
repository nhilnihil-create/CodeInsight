#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    int n;
    int ans = INF;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);
    sort(a.begin(), a.end());
    for(int i = a.at(0); i <= a.at(n - 1); i++) {
        int b = 0;
        rep(j, n) {
            b += (i - a.at(j)) * (i - a.at(j));
        }
        ans = min(ans, b);
    }
    cout << ans << endl;
}