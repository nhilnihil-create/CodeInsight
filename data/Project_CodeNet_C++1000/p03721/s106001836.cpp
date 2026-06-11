#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define sizeOf(A) (sizeof(A))/(sizeof(A[0]))
#define odd(x) ((x) % (2))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll k;
    cin >> n >> k;
    vector<pair<int, int>> A;
    FOR(i, 0, n) {
        int a, b;
        cin >> a >> b;
        A.pb(make_pair(a, b));
    }

    sort(A.begin(), A.end());
    ll x = 0, i = 0;
    while (x < k && i < A.size()) {
        x += A[i].second;
        i++;
    }
    ll size = A.size();
    //int pointer = min(A.size(), i);
    cout << A[i-1].first << "\n";
    return 0;
}
