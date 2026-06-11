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

int x, a, b;
int main() {
    cin >> x >> a >> b;
    int da = abs(x - a);
    int db = abs(x - b);
    if (da > db)
        cout << "B" << endl;
    else
        cout << "A" << endl;
    return 0;
}
