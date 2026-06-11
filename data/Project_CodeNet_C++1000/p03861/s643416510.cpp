#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

ll a,b,x;

ll f(ll n){
    if(n == -1) return 0;
    else return n/x + 1;
}
int main() {
    cin >> a >> b >> x;

    cout << f(b) - f(a-1);

    return 0;
}
