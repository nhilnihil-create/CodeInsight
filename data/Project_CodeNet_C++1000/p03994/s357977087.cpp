#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const int int_inf = 100000000;
const double eps = 1e-9;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s;
    cin >> s;
    int k;
    cin >> k;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') continue;
        if (k >= 'z' - s[i] + 1) {
            k -= 'z' - s[i] + 1;
            s[i] = 'a';
        }
        //cout << s[i] << " " << 'z' - s[i] + 1 << endl;
    }

    if (k) {
        s[s.size() - 1] = 'a' + (s[s.size()-1] - 'a' + k) % 26;
    }

    cout << s << endl;
    return 0;
}

