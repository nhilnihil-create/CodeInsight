#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll X, Y;
    scanf("%lld%lld", &X, &Y);
    if(abs(X-Y) > 1) cout << "Alice" << endl;
    else             cout << "Brown" << endl;

    return 0;
}