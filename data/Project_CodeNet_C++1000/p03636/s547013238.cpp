#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int sMiddleSize;
    cin >> s;
    vector<char> v;

    for (int i = 0; i < s.length(); i++)
    {
        v.push_back(s[i]);
    }
    sMiddleSize = v.size() - 2;

    cout << v[0] << to_string(sMiddleSize) << v[v.size()-1];
}