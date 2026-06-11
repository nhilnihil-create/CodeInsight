#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    string s, t;

    cin >> s;

    t = s[0] + to_string(s.size() - 2) + s[s.size() - 1];

    cout << t << endl;

    return 0;
}