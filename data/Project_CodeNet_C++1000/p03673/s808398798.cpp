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

    int n;
    cin >> n;
    int A[n];
    FOR(i, 0, n) {cin >> A[i];}
    if (odd(n)) {
        for (int i = n; i >= 1; i -= 2) {
            cout << A[i-1] << " ";
        }
        for (int i = 2; i <= n-1; i += 2) {
            cout << A[i-1] << " ";
        }
    } else {
        for(int i = n; i >= 2; i -= 2) {
            cout << A[i-1] << " ";
        }
        for (int i = 1; i <= n-1; i+= 2) {
            cout << A[i-1] << " ";
        }
    }

    return 0;
}
