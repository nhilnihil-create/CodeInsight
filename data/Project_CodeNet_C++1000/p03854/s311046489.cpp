#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string S;

    cin >> S;
    reverse(S.begin(), S.end());

    uint32_t len = S.length();
    uint32_t i;

    for (i = 0; i < len;)
    {
        if (S.compare(i, 6, "resare") == 0)
        {
            i += 6;
        }
        else if (S.compare(i, 5, "esare") == 0)
        {
            i += 5;
        }
        else if (S.compare(i, 5, "maerd") == 0)
        {
            i += 5;
        }
        else if (S.compare(i, 7, "remaerd") == 0)
        {
            i += 7;
        }
        else
        {
            break;
        }
    }
    if (i != len)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}