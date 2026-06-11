#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int len = s.size();

    //a~zまでを検証
    int ans = 1000;
    for (int alfa = 0; alfa < 26; alfa++)
    {
        int i, j;
        string buf = "", ss = s;
        for (i = 0; i < len; i++)
        {
            for (j = 0; j < ss.size(); j++)
            {
                if(ss[j] != 'a' + alfa)break;
            }
            if(j == ss.size())break;
            for (j = 0; j < ss.size() - 1; j++)
            {
                if(ss[j] == 'a' + alfa || ss[j + 1] == 'a' + alfa)buf += 'a' + alfa;
                else buf += ss[j];
            }
            ss = buf;
            buf = "";
        }
        ans = min(ans, i);
    }
    cout << ans << endl;
}