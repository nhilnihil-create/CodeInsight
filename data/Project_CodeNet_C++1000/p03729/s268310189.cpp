#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define sizeOf(A) (sizeof(A))/(sizeof(A[0]))
#define odd(x) ((x) % (2))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b, c;
    cin >> a >> b >> c;

    (a[a.size()-1] == b[0] && b[b.size()-1] == c[0]) ? cout << "YES\n" : cout << "NO\n";
    return 0;
}
