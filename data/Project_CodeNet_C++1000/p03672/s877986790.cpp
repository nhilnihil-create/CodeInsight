#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, x, y;
    char s[500];
    cin >> s;
    n = strlen(s);
    x = n;
    while(1)
    {
        x = x - 2;
        y = strncmp((s), (s+(x/2)), (x/2));
        if(y==0)
        {
            cout << x << endl;
            break;
        }
    }
    return 0;
}