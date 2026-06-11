#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;

int main(){
    int n;
    cin >> n;
    string s, res;
    cin >> s;
    int c = 0;
    int r = 0;
    for (int i = 0; i < n; i++) {
        c += (s[i] == '(' ? 1 : -1);
        r = max(r, -c);
    }
    res = string(r, '(') + s;
    c += r;
    while (c > 0) {
        c--;
        res.push_back(')');
    }
    cout << res << endl;
}
