#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

int main() {
    ll N, x;
    cin >> N;
    set<ll>s;
    for (int i = 0; i < N; i++) {
        cin >> x;
        s.insert(x);
    }
    if (s.size() % 2 == 0) {
        cout << s.size() - 1 << endl;
    } else {
        cout << s.size() << endl;
    }
}
