#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define sizeOf(A) (sizeof(A))/(sizeof(A[0]))
#define odd(x) ((x) % (2))
#define fastio ios_base::sync_with_stdio(false), cin.tie(0);

int main() {
    fastio;

    string s;
    cin >> s;

    set<char> A;
    FOR(i, 0, s.size()) {
        A.insert(s[i]);
    }

    if (s.size() == A.size()) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
    return 0;
}
