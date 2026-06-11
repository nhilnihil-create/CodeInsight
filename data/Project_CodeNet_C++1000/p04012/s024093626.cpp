#include<bits/stdc++.h>
using namespace std;
int i, len, Char[26], temp;
bool cond;
string s;
int main()
{
    cin >> s;
    cond = true;
    len = s.size();
    for(i=0;i<len;i++)
    {
        temp = s[i]-'a';
        Char[temp]++;
    }
    for(i=0;i<26;i++)
    {
        len = Char[i];
        if(len%2)
            {
                cond = false;
                break;
            }
    }
    if(cond)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
