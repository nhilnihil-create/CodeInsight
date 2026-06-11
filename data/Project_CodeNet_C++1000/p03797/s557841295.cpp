#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ll a, b, e, f, g;
    cin >> a >> b;
    ll c = min(a, b/2);
    e = b - (c * 2);
    if(e > 1)
    f = e / 4;
    cout << c + f << endl;


}
