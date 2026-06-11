#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    string s;
    cin >> s;
    bool flg;
    for (int delta = (s.length() - 1) / 2; delta > 0; delta--)
    {
        flg = true;
        for (int i = 0; i < delta; i++)
        {
            if (s[i] != s[i + delta])
            {
                flg = false;
            }
        }
        if (flg)
        {
            cout << delta * 2 << endl;
            return 0;
        }
    }
    return 0;
}
