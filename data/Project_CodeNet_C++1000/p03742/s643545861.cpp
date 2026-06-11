#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll x, y;
    cin >> x >> y;
    if(y>x)swap(x,y);
    cout << (x-y>=2?"Alice":"Brown") << endl;
    return 0;
}
