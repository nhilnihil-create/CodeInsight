#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string s;
    cin >> s;

    int len = s.size();

    vector<int> alpha(26, 0);
    for (int i = 0; i < len; i++)
    {
        alpha[s[i] - 97]++;
    }

    int spec = 0;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] > 0)
            spec++;
    }
    if (spec == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    int operation = len;
    for (int a = 0; a < 26; a++)
    {
        string baseStr = s;
        for (int l = len - 1; l > 1; l--)
        {
            string newStr;
            newStr.resize(l);
            for (int i = 0; i < l; i++)
            {
                if (baseStr[i] - 97 == a)
                {
                    newStr[i] = baseStr[i];
                }
                else if (baseStr[i + 1] - 97 == a)
                {
                    newStr[i] = baseStr[i + 1];
                }
                else
                {
                    if (i % 2 == 0)
                    {
                        newStr[i] = baseStr[i + 1];
                    }
                    else
                    {
                        newStr[i] = baseStr[i];
                    }
                }
            }
            baseStr = newStr;
            for (int i = 0; i < 26; i++)
            {
                alpha[i] = 0;
            }

            for (int i = 0; i < len; i++)
            {
                alpha[baseStr[i] - 97]++;
            }

            int spec = 0;
            for (int i = 0; i < 26; i++)
            {
                if (alpha[i] > 0)
                    spec++;
            }
            if (spec == 1)
            {
                break;
            }
        }
        
        int op = s.size() - baseStr.size();
        if(op < operation) operation = op;
    }

    cout << operation << endl;

    return 0;
}
