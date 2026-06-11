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

string s;
int main() {
    cin >> s;
    int n = s.length();
    int i = n;
    while (i > 0) {
        if (i >= 5) {
            if (s.substr(i - 5, 5) == "dream") {
                i -= 5;
                continue;
            } else if (s.substr(i - 5, 5) == "erase") {
                i -= 5;
                continue;
            }
            if (i >= 6) {
                if (s.substr(i - 6, 6) == "eraser") {
                    i -= 6;
                    continue;
                }
                if (i >= 7) {
                    if (s.substr(i - 7, 7) == "dreamer") {
                        i -= 7;
                        continue;
                    }
                }
            }
            cout << "NO" << endl;
            return 0;
        } else {
            break;
        }
    }
    if (i == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
