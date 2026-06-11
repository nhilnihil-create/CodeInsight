#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const int MOD = 1000000007;
using pint = pair<ll, ll>;

ll gcd(ll x, ll y) { return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int main(){
    ll N;
    cin >> N;
    ll out = 1;
    for (int i = 0; i < N; i++) {
      ll a;
      cin >> a;
      out = lcm(out, a);
    }
    cout << out<< endl;

    return 0;
}