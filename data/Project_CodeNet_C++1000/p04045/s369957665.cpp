#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define bn(n) (n).begin(), (n).end()
#define FOR(n) for(int i = 0; i < (int)n; i++)

void solve() {
    int n, k;
    cin >> n >> k;
    vector<char> v;
    for (int i = 0; i < k; i++) {
        char a;
        cin >> a;
        v.push_back(a);
    }

    bool xd = true;
    while(true) {
        string s = to_string(n);
        for (char a : s) {
            if (find(v.begin(), v.end(), a) != v.end()) {
                xd = false;
                break;
            }
        }
        if (xd) {
            cout << n << "\n";
            return;
        }
        n++;
        xd = true;
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i = 1;
    //cin >> t;
    while(t--) {
        //cout << "Case #" << i << ": ";
        solve();
        //i++;
    }
    return 0;
}
