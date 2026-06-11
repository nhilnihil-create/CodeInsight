#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define sizeOf(A) (sizeof(A))/(sizeof(A[0]))
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);

int main() {
    fastio;

    int x, a, b;
    cin >> x >> a >> b;

    if (b - a <= 0) {
        cout << "delicious\n";
    } else if (b - a <= x) {
        cout << "safe\n";
    } else {
        cout << "dangerous\n";
    }
    return 0;
}
