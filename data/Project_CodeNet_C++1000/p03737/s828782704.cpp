#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

char swapcase(char ch) {
    return (char)(ch - 'a' + 'A');
}

int main() {
    fastIO;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << swapcase(s1[0]);
    cout << swapcase(s2[0]);
    cout << swapcase(s3[0]);
    cout << endl;
}