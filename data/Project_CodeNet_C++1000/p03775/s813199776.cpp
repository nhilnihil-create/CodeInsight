#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vector<ll>>;
using vvc = vector<vector<char>>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repd(i,n) for(ll i = n - 1; i >= 0; i--)
#define all(x) x.begin(), x.end()

ll n, k, m, M = 1e9 + 7;

int main() {
cin.tie(0);
ios::sync_with_stdio(false);

cin >> n;

ll f;
for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) f = i;
}

f = n / f;

ll num = 0, prd = 1;
while(prd <= f) {
    prd *= 10;
    num++;
}

cout << num << endl;
}