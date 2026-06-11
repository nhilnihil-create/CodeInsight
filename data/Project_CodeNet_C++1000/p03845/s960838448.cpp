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
    int sum = 0;
    cin >> n;
    vector<int> t(n);
    rep(i, n) {
        cin >> t.at(i);
        sum += t.at(i);
    }
    int m;
    cin >> m;
    vector<int> p(m);
    vector<int> q(m);
    rep(i, m) cin >> p.at(i) >> q.at(i);
    rep(i, m) {
        int ans;
        ans = sum - t.at(p.at(i) - 1) + q.at(i);
        cout << ans << endl;
    }
}