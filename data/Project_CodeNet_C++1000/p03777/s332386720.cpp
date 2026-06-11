#include <bits/stdc++.h>

using namespace std;

#define fin(ans) cout << (ans) << endl;

void Main()
{
    char a, b;
    cin >> a >> b;
    if (a == 'H')
    {
        if (b == 'D')
            fin('D') else fin('H')
    }
    else
    {
        if (b == 'D')
            fin('H') else fin('D')
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
    return 0;
}