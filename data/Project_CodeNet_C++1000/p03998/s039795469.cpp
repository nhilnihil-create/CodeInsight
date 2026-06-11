#include <iostream>
#include <string>
using namespace std;
int main()
{
    int flag = -1, p, la, lb, lc, pa, pb, pc, i;
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    pa = 0;
    pb = 0;
    pc = 0;
    la = sa.size();
    lb = sb.size();
    lc = sc.size();
    p = pa;
    char c = sa[0];
    while (pa != la || pb != lb || pc != lc)
    {
        if (c == 'a')
        {
            pa++;
            flag = 0;
            if (pa == la)
            {
                break;
            }
            c = sa[pa];
        }
        else if (c == 'b')
        {
            c = sb[pb];
            flag = 1;
            if(pb == lb)
            break;
            pb++;
        }
        else if (c == 'c')
        {
            flag = 2;
            c = sc[pc];
            if(pc == lc)
            break;
            pc++;
        }
    }
    if(flag == 0)
    cout << "A";
    else if(flag == 1)
    cout << "B";
    else
    cout << "C";
    // cout << "\n";
    return 0;
}