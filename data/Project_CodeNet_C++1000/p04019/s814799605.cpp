#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int a, b, c, d;
    a = b = c = d = 0;
    for (int i = 0; i < s.size(); i++) {
        a += (s[i] == 'S');
        b += (s[i] == 'N');
        c += (s[i] == 'W');
        d += (s[i] == 'E');
    }
    if ((!!a) ^ (!!b)) puts("No");
    else if ((!!c) ^ (!!d)) puts("No");
    else puts("Yes");
}
