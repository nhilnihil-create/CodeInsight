#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a, b, x;
    cin >> a >> b >> x;

    ll count;

    if(a == 0) count = b/x+1;
    else count = b/x-(a-1)/x;

    cout << count << endl;
    return 0;
}