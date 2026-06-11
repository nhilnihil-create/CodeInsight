#include <string>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, w;
    cin >> h >> w;
    string p[h];
    string p2[2 * h];
    for (int i = 0; i < h; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < h; i++)
    {
        p2[2 * i] = p[i];
        p2[2 * i + 1] = p[i];
    }
    for (int i = 0; i < 2 * h; i++)
    {
        cout << p2[i] << endl;
    }

    return 0;
}