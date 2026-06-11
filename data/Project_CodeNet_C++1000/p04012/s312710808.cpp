#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
void setIO(string name = "b") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    //setIO();
    string str; cin >> str;
    int a[26] = { 0 };
    for (char c : str) {
        a[c - 'a']++;
    }
    bool ok = 1;
    for (int i : a) {
        if (i % 2 != 0) {
            ok = 0;
        }
    }
    if (ok) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}