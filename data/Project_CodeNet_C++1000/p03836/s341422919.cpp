#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
int x, y, tx, ty;

int main() {
    cin >> x >> y >> tx >> ty;
    int dx = tx - x;
    int dy = ty - y;
    string ans = "";
    auto add = [&](int n, char c){
        while (n) {
            ans += c;
            --n;
        }
    };
    // +dx +dy +1x -dy -1y -dx -1x +1y
    add(dx, 'R');
    add(dy, 'U');
    add(1, 'R');
    add(dy + 1, 'D');
    add(dx + 1, 'L');
    add(1, 'U');
    // +dy +dx +1y -dx -1x -dy -1y +1x
    add(dy, 'U');
    add(dx, 'R');
    add(1, 'U');
    add(dx + 1, 'L');
    add(dy + 1, 'D');
    add(1, 'R');
    cout << ans << endl;
    return 0;
}
