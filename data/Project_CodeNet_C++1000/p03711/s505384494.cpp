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

    int x, y;
    cin >> x >> y;

    if ((x <= 7 && odd(x)) || (x >=8 && !(odd(x)))) {
        x = 1;
    } else if (x == 4 || x == 6 || x == 9 || x == 11) {
        x = 2;
    } else {
        x = 3;
    }
    if ((y <= 7 && odd(y)) || (y >=8 && !(odd(y)))) {
        y = 1;
    } else if (y == 4 || y == 6 || y == 9 || y == 11) {
        y = 2;
    } else {
        y = 3;
    }
    (x == y) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}
