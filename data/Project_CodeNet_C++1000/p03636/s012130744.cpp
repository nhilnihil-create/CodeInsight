#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    cout << s.front() << s.size() - 2 << s.back() << endl;
}