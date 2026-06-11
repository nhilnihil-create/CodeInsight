#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    cout << s[0] << s.size() - 2 << s[s.size() - 1] << endl;
}