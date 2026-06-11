#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string s;
    cin >> s;
    int n = s.size();
    puts(bool(n & 1) ^ bool(s[0] != s[n - 1]) ? "Second" : "First");
}