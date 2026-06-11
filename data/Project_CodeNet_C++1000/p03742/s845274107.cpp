#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const double EPS = 1e-10;
const ll INF = 100000000;
const ll MOD = 1000000007;

ll x, y;

int main() {
    cin >> x >> y;
    if (abs(x-y) <= 1) puts("Brown");
    else puts("Alice");
}

