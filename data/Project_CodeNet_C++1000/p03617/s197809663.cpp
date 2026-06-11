#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 条件を見落としていませんか？
int main () {
    ll Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;
    ll a = N/2, b = N%2;
    cout << a*min({8*Q, 4*H, 2*S, D}) + b*min({4*Q, 2*H, S}) << endl;
}