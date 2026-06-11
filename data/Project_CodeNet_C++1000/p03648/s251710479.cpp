#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 998244353
using namespace std;
int main() {
    ll k;
    cin >> k;
    vector<ll> a(50, k / 50 + 1);
    for(int i = 0; i < 50; i++) {
        a[i] += i;
    }
    int q = 50 - k % 50;
    while(q--) {
        auto ind = max_element(all(a));
        *ind -= 51;
        for(int i = 0; i < 50; i++) {
            a[i] += 1;
        }
    }
    cout << 50 << endl;
    for(auto e : a) {
        cout << e << " ";
    }
    cout << endl;
}