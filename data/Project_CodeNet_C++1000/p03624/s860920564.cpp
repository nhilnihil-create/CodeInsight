#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string S;
    cin >> S;
    string ans = "";
    for (char c = 'a'; c <= 'z'; ++c)
    {
        bool found = false;
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == c)
            {
                found = true;
                break;
            }
        }
        if (found == false)
        {
            ans = c;
            break;
        }
    }
    if (ans == "")
    {
        cout << "None" << endl;
    }
    else
    {
        cout << ans << endl;
    }
}