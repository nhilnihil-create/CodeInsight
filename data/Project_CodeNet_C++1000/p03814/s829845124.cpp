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
    int start, end;
    rep(i, s.length())
    {
        if (s[i] == 'A')
        {
            start = i;
            break;
        }
    }
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == 'Z')
        {
            end = i;
            break;
        }
    }
    cout << end - start + 1 << endl;
    return 0;
}
