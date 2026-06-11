#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string temp = s;
    reverse(s.begin(), s.end());
    if(s == temp) printf("Yes");
    else printf("No\n");
    return 0;
}