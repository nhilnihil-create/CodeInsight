#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    char c = sa[0];
    sa.erase(sa.begin() + 0);
    while (1)
    {
        // cout << c << endl;
        if (c == 'a')
        {
            if (sa.empty())
            {
                cout << "A" << endl;
                break;
            }
            c = sa[0];
            sa.erase(sa.begin() + 0);
        }
        if (c == 'b')
        {
            if (sb.empty())
            {
                cout << "B" << endl;
                break;
            }
            c = sb[0];
            sb.erase(sb.begin() + 0);
        }
        if (c == 'c')
        {
            if (sc.empty())
            {
                cout << "C" << endl;
                break;
            }
            c = sc[0];
            sc.erase(sc.begin() + 0);
        }
    }
    return 0;
}
