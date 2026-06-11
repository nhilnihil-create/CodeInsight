#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;

    set<ll> s;
    rep(i, n) {
        ll a;
        cin >> a;
        if (s.find(a) != s.end())
            s.erase(a);
        else
            s.insert(a);
    }

    cout << s.size() << endl;
    return 0;
}
