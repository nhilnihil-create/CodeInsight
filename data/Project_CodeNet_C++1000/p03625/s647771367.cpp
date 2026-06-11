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
    ll A[n];
    FOR(i, 0, n) {cin >> A[i];}
    sort(A, A + n);
    reverse(A, A + n);
    vector<ll> duplicates;
    FOR(i, 0, n-1) {
        if (A[i] == A[i+1]) {
            duplicates.pb(A[i]);
            i++;
        }
    }
    if (duplicates.size() < 2) {
        cout << 0 << "\n"; 
    } else {
        cout << duplicates[0]*duplicates[1] << "\n";
    }
    return 0;
}
 