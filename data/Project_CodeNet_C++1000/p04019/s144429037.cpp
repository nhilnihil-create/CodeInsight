#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    string s;
    cin >> s;
    int n = s.length();

    map<char, int> T;
    rep(i, n)
    {
        T[s[i]] = 1;
    }

    if (T['N'] && T['W'] && T['S'] && T['E'])
        cout << "Yes" << endl;
    else if (T['N'] && !T['W'] && T['S'] && !T['E'])
        cout << "Yes" << endl;
    else if (!T['N'] && T['W'] && !T['S'] && T['E'])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}