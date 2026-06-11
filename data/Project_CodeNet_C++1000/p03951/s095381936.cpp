#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll N;
    string s, t;
    ll count = 0;
    cin >> N >> s >> t;
    for(ll i = 0;i < N;i++) {
        string a(s.begin() + s.size() - 1 - i, s.end());
        string b(t.begin(), t.begin() + i + 1);
        if(a == b) count = max(count, (ll)a.size());
    }
    cout << s.size() + t.size() - count << endl;
    return 0;
}
