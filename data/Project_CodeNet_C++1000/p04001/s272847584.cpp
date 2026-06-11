#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    ll sum = 0;
    ll count = 0;
    for (int i = 0; i < (1 << n - 1); i++) {
        for (int j = 0; j < n; j++) {
            sum += (s.at(n - j - 1) - '0') * pow(10, count);
            count++;
            if (i & (1 << j)) count = 0;
        }
        count = 0;
    }

    cout << sum << endl;
}
