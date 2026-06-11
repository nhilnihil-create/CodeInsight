#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int main () {
    ll x, y;
    cin >> x >> y;
    if (x < y) swap(x, y);
    if (x - y <= 1) cout << "Brown\n";
    else cout << "Alice\n";
    return 0;
}
