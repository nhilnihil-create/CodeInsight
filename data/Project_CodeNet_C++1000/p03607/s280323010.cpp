#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
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
    set<ll> A;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        if (A.count(x)) {
            A.erase(x);
        } else {
            A.insert(x);
        }
    }
    cout << A.size() << "\n";
    return 0;
}   
