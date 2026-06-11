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


int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> num(100000, 0);
    rep(i, n) {
        cin >> a.at(i) >> b.at(i);
        num.at(a.at(i) - 1) += b.at(i);
    }
    rep(i, 100000) {
        if (k - num.at(i) <= 0) {
            cout << i + 1 << endl;
            return 0;
        }
        k -= num.at(i);
    }
}