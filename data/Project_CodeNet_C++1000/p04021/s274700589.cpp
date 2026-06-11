#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int maxn = 1e5 + 10;
int n, a[maxn];
set<int> s;
map<int, int> mp;
vector<int> v1, v2;

int main() {
    __;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a[i] = x;
        s.insert(x);
    }
    int ct = 1;
    for (auto i:s) {
        mp[i] = ct;
        ++ct;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            v1.push_back(mp[a[i]]);
            if (mp[a[i]] & 1); else cnt++;
        } else {
            v2.push_back(mp[a[i]]);
        }
    }
    cout << cnt << endl;
    return 0;
}