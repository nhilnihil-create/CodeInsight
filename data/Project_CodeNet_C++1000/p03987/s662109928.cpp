#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
int main() {
    int n;
    cin >> n;
    vector<int> a(n), ind(n);
    for(size_t i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        ind[a[i]] = i;
    }
    set<int> A;
    A.insert(-1);
    A.insert(n);
    vector<ll> al(n, 0); //閉区間
    vector<ll> ar(n, 0); //閉区間
    for(int i = 0; i < n; i++) {
        auto itr = A.lower_bound(ind[i]);
        ar[ind[i]] = *itr;
        itr--;
        al[ind[i]] = *itr;
        A.insert(ind[i]);
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        ans += (i + 1) * (ind[i] - al[ind[i]]) * (ar[ind[i]] - ind[i]);
    }
    cout << ans << endl;
}
