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
    string a, b, c; cin >> a >> b >> c;
    int p1 = 0, p2 = 0, p3 = 0; int cur = 1;
    char ans;
    while (p1 <= a.length() && p2 <= b.length() && p3 <= c.length()) {
        if (cur == 1) {
            if (p1 == a.length()) {
                ans = 'A';
                break;
            }
            cur = (a[p1] - 'a') + 1;
            p1++;
        } else if (cur == 2) {
            if (p2 == b.length()) {
                ans = 'B';
                break;
            }
            cur = (b[p2] - 'a') + 1;
            p2++;
        } else if (cur == 3) {
            if (p3 == c.length()) {
                ans = 'C';
                break;
            }
            cur = (c[p3] - 'a') + 1;
            p3++;
        }
    }
    cout << ans << "\n";
}