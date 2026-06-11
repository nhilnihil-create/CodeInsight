#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> pct(h);
    for (int i = 0; i < h; i++)
    {
        cin >> pct.at(i);
    }
    string s;
    for (int i = 0; i < w + 2; i++)
    {
        s += '#';
    }
    cout << s << endl;
    for (int i = 0; i < h; i++)
    {
        putchar('#');
        cout << pct.at(i);
        putchar('#');
        putchar('\n');
    }
    cout << s << endl;
}