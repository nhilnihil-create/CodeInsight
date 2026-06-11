#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{

    string S;
    cin >> S;
    bool n, w, s, e;
    n = false;
    w = false;
    s = false;
    e = false;
    for (int i = 0; i < S.size(); ++i)
    {
        switch (S[i])
        {
        case 'N':
            n = true;
            break;
        case 'W':
            w = true;
            break;
        case 'S':
            s = true;
            break;
        case 'E':
            e = true;
            break;

        default:
            break;
        }
    }
    if ((n != s) || (w != e))
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}
