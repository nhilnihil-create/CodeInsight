#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define sizeOf(A) (sizeof(A))/(sizeof(A[0]))
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
const ll MOD = 1e9 + 7;

int main() {
    fastio;

    ll x, a, b;
    cin >> x >> a >> b;
    if (abs(x-a) > abs(x-b)) {
        cout << "B\n";
    } else {
        cout << "A\n";
    }
    return 0;
}
