#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    long long k = 0, n = s.length();
    for (long long i = 0; i < n; i++)
        if (s[i] == 'p') k++;
    cout << n / 2 - k;
}