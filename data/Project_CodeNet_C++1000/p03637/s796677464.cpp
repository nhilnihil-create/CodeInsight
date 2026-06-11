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
    int working = 0;
    int evens = 0;
    FOR(i, 0, n) {
        cin >> A[i];
        if (A[i] % 4 == 0) {
            working++;
        }
        if (!odd(A[i])) {evens++;}
    }
    evens -= working;
    if (working + (evens/2)>= n/2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
