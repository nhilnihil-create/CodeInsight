#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a == 5 && b == 7 && c == 5) || 
        (a == 5 && b == 5 && c == 7) || 
        (a == 7 && b == 5 && c == 5)) {
            cout << "YES\n";
            return 0;
        } else {
            cout << "NO\n";
        }
}