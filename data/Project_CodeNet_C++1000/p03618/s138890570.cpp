#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long int n = s.size();
    long long int ans = n*(n - 1)/2 + 1;
    long long int num[26] = {0};
    for(int i = 0; i < n; ++i) num[s[i] - 'a']++;
    for(int i = 0; i < 26; ++i) {
        if(num[i] >= 2) ans -= num[i]*(num[i]-1)/2;
    }

    cout << ans << '\n';

    return 0;
}
