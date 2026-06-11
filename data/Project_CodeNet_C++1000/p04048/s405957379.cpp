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

ll gcd(ll x, ll y) {
    if(y == 0) {
        return x;
    }
    else {
        return gcd(y, x%y);
    }
}

int main() {
    ll n, x;
    cin >> n >> x;

    cout << 3LL*(n - gcd(n, x)) << endl;
    return 0;
}