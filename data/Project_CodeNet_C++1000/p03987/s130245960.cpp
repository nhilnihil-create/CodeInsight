#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N+1);
    vector<int> index(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        index[A[i]] = i;
    }
    ll ans = 0;
    set<int> position;
    for (int i = 1; i <= N; i++) {
        auto itr = position.upper_bound(index[i]);
        ll l, r;
        if (itr == position.end()) r = N + 1 - index[i];
        else r = (*itr) - index[i];

        if (itr == position.begin()) l = index[i];
        else l = index[i] - *(--itr);

        ans += i * l * r;
        position.insert(index[i]);
    }
    cout << ans << endl;
}
