#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string s;
    map<char, int> m;
    cin >> s;
    for(auto u : s)
        m[u]++;
    for(auto u : m)
    {
        if(u.second%2)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}

