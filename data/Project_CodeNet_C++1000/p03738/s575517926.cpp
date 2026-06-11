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

string s1, s2;
int main() {
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    if (n > m)
        cout << "GREATER" << endl;
    else if (n < m)
        cout << "LESS" << endl;
    else {
        int i = 0;
        while (i < n) {
            if (s1[i] < s2[i]) {
                cout << "LESS" << endl;
                exit(0);
            }
            else if (s1[i] > s2[i]) {
                cout << "GREATER" << endl;
                exit(0);
            }
            else {
                ++i;
            }
        }
        cout << "EQUAL" << endl;
    }
    return 0;
}
