#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    n -= 2;
    string t = to_string(n);
    string ans = s[0] + t + s[s.size() - 1];
    cout << ans << endl;
    return 0;
}