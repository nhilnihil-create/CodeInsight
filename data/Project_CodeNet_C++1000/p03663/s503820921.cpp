#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld PI = acos(-1);
const ll MAX = 1e12;
const ll INF = 1e17;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 3e5 + 10;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("mines.in", "r", stdin);
    //freopen("mines.out", "w", stdout);
    string s = "999999999999999999";

    string N = "";

    fr(i, 11) {
        int l = -1, r = 10;
        if (i == 0)
            l = 0;
        while (r - l > 1) {
            int m = (l + r) / 2;
            string t = s;
            t[i] = (char)('0' + m);
            cout << "? " << t << endl;
            string answer;
            cin >> answer;
            if (answer == "Y")
                r = m;
            else
                l = m;
        }
        N += (char)('0' + r);
        s[i] = (char)('0' + r);

        if (i && r == 0) {
            if (s[i - 1] != '9') {
                string q = s.substr(0, i - 1) + '9';
                cout << "? " << q << endl;
                string answer;
                cin >> answer;
                if (answer == "Y") {
                    cout << "! " << N.substr(0, (int)N.size() - 1) << endl;
                    return 0;
                }
            }
            else if (N != "90") {
                string q = s.substr(0, i - 1) + "00";
                cout << "? " << q << endl;
                string answer;
                cin >> answer;
                if (answer == "N") {
                    cout << "! " << N.substr(0, (int)N.size() - 1) << endl;
                    return 0;
                }
            }
            else {
                string q = "10";
                cout << "? " << q << endl;
                string answer;
                cin >> answer;
                if (answer == "N") {
                    cout << "! " << N.substr(0, (int)N.size() - 1) << endl;
                    return 0;
                }
            }

        }
    }
}
