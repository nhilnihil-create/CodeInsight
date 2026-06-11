#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define sizeOf(A) (sizeof(A))/(sizeof(A[0]))
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);
const ll MOD = 1e9 + 7;

bool isEven (string s) {
    if (odd(s.size())) {
        return false;
    } else {
        FOR(i, 0, s.size()/2) {
            if (s[i] != s[i+s.size()/2]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    fastio;

    string s;
    cin >> s;

    s.erase(s.size()-1, 1);
    while (!isEven(s)) {
        s.erase(s.size()-1, 1);
    }
    cout << s.size() << "\n";
    return 0;
}
