#include <bits/stdc++.h>
using namespace std;
string s;

int main()
{
    cin >> s;
    int len = s.length();
    if(len & 1)
    {
        if(s[0] == s[len - 1]) cout << "Second";
        else cout << "First";
    }
    else
    {
        if(s[0] ^ s[len - 1]) cout << "Second";
        else cout << "First";
    }
}