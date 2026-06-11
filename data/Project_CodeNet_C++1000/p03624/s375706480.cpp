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
        if (S.find(c) == string::npos)
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
