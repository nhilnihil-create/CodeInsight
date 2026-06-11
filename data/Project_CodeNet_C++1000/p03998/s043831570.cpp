#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    ///queに格納
    queue<char> a, b, c;
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    rep(i, sa.length()) a.push(sa[i]);
    rep(i, sb.length()) b.push(sb[i]);
    rep(i, sc.length()) c.push(sc[i]);
    a.push('z');
    b.push('z');
    c.push('z');

    //ゲームスタート
    char p = 'a'; //次を示す
    while (1)
    {
        if (p == 'a')
        {
            if (a.front() == 'z')
            {
                cout << 'A' << endl;
                return 0;
            }
            p = a.front();
            a.pop();
        }
        if (p == 'b')
        {
            if (b.front() == 'z')
            {
                cout << 'B' << endl;
                return 0;
            }
            p = b.front();
            b.pop();
        }
        if (p == 'c')
        {
            if (c.front() == 'z')
            {
                cout << 'C' << endl;
                return 0;
            }
            p = c.front();
            c.pop();
        }
    }
}