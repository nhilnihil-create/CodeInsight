#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    string a, b;
    cin >> a >> b;
    if (a == b)
        cout << "EQUAL";
    else if (a.size() > b.size())
        cout << "GREATER";
    else if (a.size() < b.size())
        cout << "LESS";
    else {
        if (a[0] > b[0])
            cout << "GREATER";
        else if (a[0] < b[0])
            cout << "LESS";
    }
}