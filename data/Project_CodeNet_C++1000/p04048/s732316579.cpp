#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stdlib.h>
using namespace std;
typedef long long ll;
ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x%y);
}
int main() {
    ll x, n;
    cin >> n >> x;
    ll t = gcd(x, n);
    ll u = n/t, v = 3*u-3;
    cout << t*v;
    return 0;
}