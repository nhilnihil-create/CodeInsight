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

    int n;
    cin >> n;
    int A[n];
    int sum = 0;
    FOR(i, 0, n) {
        cin >> A[i];
        sum += A[i];
    }
    int size = sizeOf(A);
    sort(A, A + size);
    int i = 0;
    while (sum % 10 == 0 && i < n) {
        if (A[i] % 10 != 0) {
            sum -= A[i];
        }
        i++;
    }
    if (sum % 10 != 0) {
        cout << sum << "\n";
    } else {
        cout << 0 << "\n";
    }
    return 0;
}
