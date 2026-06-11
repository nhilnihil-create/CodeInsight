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
    sort(s.begin(), s.end());
    rep(i, s.length() - 1)
    {
        if (s[i] == s[i + 1])
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;

    return 0;
}
