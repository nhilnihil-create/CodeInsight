#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    cin >> s;
    printf("%c%d%c\n", s[0], s.size() - 2, s[s.size() - 1]);
    return 0;
}