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

int main() {
    fastio;

    string s;
    cin >> s;
    bool characters[26];
    FOR(i, 0, 26) {
        characters[i] = false;
    }
    FOR(i, 0, s.size()) {
        int x = s[i] - 96;
        characters[x-1] = true;
    }
    bool possible = false;
    FOR(i, 0, 26) {
        if (!characters[i]) {
            possible = true;
            char c = i + 1 + 96;
            cout << c << "\n";
            break;
        }
    }
    if (!possible) {cout << "None\n";}
    return 0;
}
