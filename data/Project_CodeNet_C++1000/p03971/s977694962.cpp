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
void setIO(string name = "2016B") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    //setIO();
    int n, a, b; string str; cin >> n >> a >> b >> str;
    int ac = 0, bc = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'a' && ac + bc < a + b) {
            cout << "Yes" << "\n";
            ac++;
        } else if (str[i] == 'b' && ac + bc < a + b && bc < b) {
            cout << "Yes" << "\n";
            bc++;
        } else {
            cout << "No" << "\n";
        }
    }
}