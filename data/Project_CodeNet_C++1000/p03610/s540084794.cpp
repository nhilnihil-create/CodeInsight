#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, result = ""; cin >> s;
    for (int i = 0; i < s.length(); i += 2) result += s[i];
    cout << result << "\n";
}