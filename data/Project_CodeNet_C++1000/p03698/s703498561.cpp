#include <iostream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool has[26];
    for (int i = 0; i < 26; i++)
        has[i] = false;
    for (int i = 0; i < s.length(); i++)
    {
        int idx = int(s[i] - 'a');
        if (has[idx])
        {
            cout << "no" << endl;
            return 0;
        }
        else
            has[idx] = true;
    }
    cout << "yes" << endl;
    return 0;
}
