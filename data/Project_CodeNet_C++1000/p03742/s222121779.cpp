#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;

int main() {
    ll x, y;
    cin >> x >> y;
    cout << ((abs(x-y)<=1) ? "Brown" : "Alice") << endl;
    return 0;
}