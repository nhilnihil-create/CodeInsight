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

    int n, k;
    cin >> n >> k;
    int A[n];
    FOR(i, 0, n) {cin >> A[i];}
    sort(A, A + n);
    int sum = 0;
    FOR(i, 0, k) {
        sum += A[n-1-i];
    }
    cout << sum << "\n";
    return 0;
}
	