#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int N = S.size(), num = 0;
    bool check = true;

    while (num != N)
    {
        if (S.substr(num, 6) == "eraser")
        {
            num += 6;
        }
        else if (S.substr(num, 5) == "erase")
        {
            num += 5;
        }
        else if (S.substr(num, 7) == "dreamer" && S.substr(num + 5, 5) != "erase")
        {
            num += 7;
        }
        else if (S.substr(num, 5) == "dream")
        {
            num += 5;
        }
        else
        {
            check = false;
            break;
        }
    }
    if (check)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}