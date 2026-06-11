#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    long index;
    cin >> s;
    vector<char> v;

    for (long i = 0; i < s.length(); i++)
    {	index = i + 1;
        if (index % 2 != 0)
        {
            v.push_back(s[i]);
        }
    }

    for (long i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
}
