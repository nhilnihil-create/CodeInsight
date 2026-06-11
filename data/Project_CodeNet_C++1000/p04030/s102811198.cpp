#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define bn(n) (n).begin(), (n).end()
#define FOR(n) for(int i = 0; i < (int)n; i++)


void solve() {
    string s;
    cin >> s;
    while(s.find('B') != string::npos) {
        if (s.find('B') != 0) {
            s.erase(s.find('B')-1, 2);
        } else {
            s.erase(s.find('B'), 1);
        }
    }
    cout << s << "\n";
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
