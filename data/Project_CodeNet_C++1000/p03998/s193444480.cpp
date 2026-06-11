#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string sa, sb, sc;

    cin >> sa >> sb >> sc;

    int ia=0, ib=0, ic=0;

    char nn = 'a';

    while(1)
    {
        if(nn == 'a')
        {
            if(ia == sa.size())
            {
                cout << "A" << endl;
                break;
            }
            nn = sa[ia];
            ++ia;
        }
        else if(nn == 'b')
        {
            if(ib == sb.size())
            {
                cout << "B" << endl;
                break;
            }
            nn = sb[ib];
            ++ib;
        }
        else if(nn == 'c')
        {
            if(ic == sc.size())
            {
                cout << "C" << endl;
                break;
            }
            nn = sc[ic];
            ++ic;
        }


    }

    return 0;
}

