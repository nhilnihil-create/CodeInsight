#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll Q, H, S, D;
    ll N;
    cin >> Q >> H >> S >> D >> N;
    S = min(S, min(2*H, 4*Q));
    cout << min(2*S, D)*(N/2) + (N%2)*S << endl;



    return 0;
}