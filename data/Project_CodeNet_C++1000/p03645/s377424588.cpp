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

    int n, m;
    cin >> n >> m;
    vector<bool> A;
    FOR(i, 0, n) {
        A.pb(false);
    }
    bool possible = false;
    FOR(i, 0, m) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            if (A[b-1]) {
                possible = true;
            }
            A[b-1] = true;
        }
        if (b == n) {
            if (A[a-1]) {
                possible = true;
            }
            A[a-1] = true;
        }
    }
    (possible) ? cout << "POSSIBLE\n" : cout << "IMPOSSIBLE\n";
    return 0;
}
