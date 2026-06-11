#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    vector<int> m(26, 0);
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
    {
        m[s[i] - 'a']++;
    }

    for(int i = 0; i < 26; ++i)
    {
        if(!m[i])
        {
            cout <<  char(i + 'a') << "\n";
            return 0;
        }
    }
    cout << "None" << "\n";
    return 0;
}