#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = b * (n - 1) + a - (a * (n - 1) + b) + 1;
    cout << (ans > 0 ? ans : 0) << '\n';
}
