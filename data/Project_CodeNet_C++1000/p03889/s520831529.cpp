#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    string tmp = str;
    reverse(tmp.begin(), tmp.end());
    for (size_t i = 0; i < str.size(); ++i)
    {
        char& ch = tmp[i];
        if (ch == 'b')
            ch = 'd';
        else if (ch == 'd')
            ch = 'b';
        else if (ch == 'p')
            ch = 'q';
        else if (ch == 'q')
            ch = 'p';
    }
    printf("%s\n", tmp == str ? "Yes" : "No");
    cin >> ws;
    return 0;
}