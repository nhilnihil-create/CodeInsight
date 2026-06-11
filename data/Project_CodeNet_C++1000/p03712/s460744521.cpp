#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H,W;
    cin >> H >> W;
    string str[H];

    for(int i=0; i<H; i++) cin >> str[i];

    for(int i=-1; i<=W; i++) cout << '#';
    cout << endl;

    for(int i=0; i<H; i++)
    {
        cout << '#' << str[i] << '#' << endl;
    }

    for(int i=-1; i<=W; i++) cout << '#';
    cout << endl;

    return 0;
}