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
int n, m, k, ans;

string s;
int main() {
    cin >> s;
    int n = s.length();
    if (s[0] == s[n - 1])
        --n;
    if (n & 1)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
    return 0;
}
