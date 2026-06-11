#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if(s[0] == '9' || s[1] == '9') printf("Yes\n");
    else printf("No\n");
    return 0;
}