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

string a, b, c;
int i, j, k;
int main() {
    cin >> a >> b >> c;
    char cur = 'a';
    while (1) {
        if (cur == 'a') {
            if (i == a.length()) {
                cout << "A" << endl;
                return 0;
            }
            cur = a[i++];
        } else if (cur == 'b') {
            if (j == b.length()) {
                cout << "B" << endl;
                return 0;
            }
            cur = b[j++];
        } else {
            if (k == c.length()) {
                cout << "C" << endl;
                return 0;
            }
            cur = c[k++];
        }
    }
    return 0;
}
