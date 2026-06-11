#include <iostream>
#include <iomanip>
#include <string>

typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for(ll i=init;i<(n);i++)

int main() {
    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll num = 0;
    repi(i, s.size(), 0) {
        num = s[i] == 'a' ? 0 : 'z' - s[i] + 1;
        k -= num;
        if (k >= 0) {
            s[i] = 'a';
        } else {
            k += num;
        }
    }
    if (k > 0) {
        k %= 26;
        repi(i, k, 0) {
            if (s[s.size() - 1] == 'z')s[s.size() - 1] = 'a';
            else s[s.size() - 1]++;
        }
    }

    cout << s << endl;
    return 0;
}