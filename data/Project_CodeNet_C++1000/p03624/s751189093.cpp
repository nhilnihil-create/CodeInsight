#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    string s;
    cin >> s;
    char alph[26] = {0};
    rep(i, s.size())
    {
        int d;
        d = s[i] - 'a';
        alph[d]++;
    }
    rep(i, 26)
    {
        if (alph[i] == 0)
        {
            char out = i + 'a';
            cout << out << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}