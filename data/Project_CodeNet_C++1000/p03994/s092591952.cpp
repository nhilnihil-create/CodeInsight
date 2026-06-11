#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20)
#define int long long
#define double long double
const int INF = 1e18, MOD = 1e9 + 7;

string s;
int k;

signed main() {
    INCANT;
    cin>>s>>k;
    for (int i = 0; i < s.size(); i++) {
        if (i == s.size() - 1) {
            k %= 26;
            s[i] = (s[i] - 'a' + k) % 26 + 'a';
        } else {
            int t = ('z' - s[i] + 1) % 26;
            if (k >= t) {
                k -= t;
                s[i] = 'a';
            }
        }
    }
    cout<<s<<endl;
}