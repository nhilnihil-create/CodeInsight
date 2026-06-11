#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<long long> a(30, 0);
    long long ans = (long long)n*(n+1)/2;
    for (auto c : s) ++a[c-'a'];
    for (auto c : a) ans -= c*(c+1)/2;
    cout << ++ans << endl;
    return 0;
}