#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;

    unsigned int i = 0;
    while (i < S.size())
    {
        if (S.substr(i, 8) == "dreamera")
        {
            i += 5;
        }
        else if (S.substr(i, 7) == "dreamer")
        {
            i += 7;
        }
        else if (S.substr(i, 5) == "dream")
        {
            i += 5;
        }
        else if (S.substr(i, 6) == "eraser")
        {
            i += 6;
        }
        else if (S.substr(i, 5) == "erase")
        {
            i += 5;
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}