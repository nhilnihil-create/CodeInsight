#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    string s;
    cin >> s;
    ll k;
    cin >> k;
    char last = '{';
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'a') {
            continue;
        }
        if(last - s[i] <= k) {
            k -= (last - s[i]);
            s[i] = 'a';
        }
    }
    k %= 26;
    s.back() += k;
    cout << s << endl;
}
