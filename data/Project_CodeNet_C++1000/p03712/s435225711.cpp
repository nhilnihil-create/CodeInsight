// https://atcoder.jp/contests/abc152/tasks/abc152_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    string row = "##";
    for (int i = 0; i < w; i++)
    {
        row += "#";
    }
    cout << row << endl;

    for (int i = 0; i < h; i++)
    {
        string s;
        cin >> s;
        cout << "#" + s + "#" << endl;
    }

    cout << row << endl;
    return 0;
}
