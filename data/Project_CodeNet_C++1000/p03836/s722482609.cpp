#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    string ans = "";

    for (int i = 0; i < tx - sx; i++)ans += "R";
    for (int i = 0; i < ty - sy + 1; i++)ans += "U";
    for (int i = 0; i < tx - sx + 1; i++)ans += "L";
    for (int i = 0; i < ty - sy + 1; i++)ans += "D";
    ans += "RD";

    for (int i = 0; i < tx - sx + 1; i++)ans += "R";
    for (int i = 0; i < ty - sy + 1; i++)ans += "U";
    for (int i = 0; i < tx - sx + 1; i++)ans += "L";
    for (int i = 0; i < ty - sy; i++)ans += "D";
/*
    int x = sx,y = sy;
    for (int i = 0; i < (int)ans.size(); i++)
    {
        if(ans[i] == 'R')x++;
        if(ans[i] == 'D')y--;
        if(ans[i] == 'L')x--;
        if(ans[i] == 'U')y++;
        cout << x << " " << y << endl;
    }
*/
    cout << ans << endl;
}