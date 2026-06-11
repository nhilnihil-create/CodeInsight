#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, A, B;
    cin >> N >> A >> B;

    ll sum_max = A + B * (N-1);
    ll sum_min = A * (N-1) + B;
    cout << max(0LL, sum_max - sum_min + 1) << endl;

    return 0;
}
