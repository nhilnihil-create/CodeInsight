#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll s = 0, e = 0, n = 0, w = 0;
    string S;
    cin >> S;
    for(auto &c: S) {
        if(c == 'N') n++;
        if(c == 'S') s++;
        if(c == 'E') e++;
        if(c == 'W') w++;
    }
    cout << ((!s == !n) && (!e == !w) ? "Yes" : "No") << endl;
    return 0;
}
