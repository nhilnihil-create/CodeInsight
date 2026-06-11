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
    string o, e, ans;
    cin >> o >> e;
    rep(i, e.size()) {
        ans.push_back(o.at(i));
        ans.push_back(e.at(i));
    }
    if (o.size() - e.size() == 1) {
        ans.push_back(o.at(o.size() - 1));
    }
    cout << ans << endl;
}