#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    string buf = s;
    string target = "()";
    if(!buf.empty())
    {
        string::size_type pos = 0;
        while((pos = buf.find(target ,0)) != string::npos)
        {
            buf.replace(pos, target.length(), "");
        }
    }

    int len = buf.length();

    int p = 0, m = 0;
    for (int i = 0; i < len; i++)
    {
        if(buf[i] == '(')p++;
        else m++;
    }
    
    for (int i = 0; i < m; i++)cout << "(";
    cout << s;
    for (int i = 0; i < p; i++)cout << ")";
    cout << endl;
}