#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        vector<ll> s(3, 0);
        cin >> s[0] >> s[1] >> s[2];
        sort(s.begin(), s.end());
        cout << s[0] + s[1] << endl;
}
